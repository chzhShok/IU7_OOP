#pragma once

#include "hash_table.h"

template<typename Key, typename Value>
Value &HashTable<Key, Value>::operator[](const Key &key) {
    size_t bucket_idx = hash(key) % buckets_.size();
    auto &bucket = buckets_[bucket_idx];

    for (auto &pair: bucket)
        if (pair.first == key)
            return pair.second;

    bucket.emplace_back(key, Value());
    ++size_;

    if (getLoadFactor() >= max_load_factor_)
        rehash(buckets_.size() * 2);

    return bucket.back().second;
}

template<typename Key, typename Value>
const Value &HashTable<Key, Value>::operator[](const Key &key) const {
    return at(key);
}

template<typename Key, typename Value>
Value &HashTable<Key, Value>::at(const Key &key) {
    size_t bucket_idx = hash(key) % buckets_.size();
    auto &bucket = buckets_[bucket_idx];

    for (auto &pair: bucket)
        if (pair.first == key)
            return pair.second;

    time_t currentTime = time(nullptr);
    throw IndexError(__FILE__, typeid(*this).name(), __LINE__, ctime(&currentTime));
}

template<typename Key, typename Value>
const Value &HashTable<Key, Value>::at(const Key &key) const {
    size_t bucket_idx = hash_function_(key) % buckets_.size();
    const auto &bucket = buckets_[bucket_idx];

    for (const auto &pair: bucket)
        if (pair.first == key)
            return pair.second;

    time_t currentTime = time(nullptr);
    throw IndexError(__FILE__, typeid(*this).name(), __LINE__, ctime(&currentTime));
}

template<typename Key, typename Value>
HashTable<Key, Value> &HashTable<Key, Value>::operator=(const HashTable &other) {
    if (this != &other) {
        clear();
        buckets_ = other.buckets_;
        size_ = other.size_;
        max_load_factor_ = other.max_load_factor_;
    }

    return *this;
}

template<typename Key, typename Value>
HashTable<Key, Value> &HashTable<Key, Value>::operator=(HashTable &&other) noexcept {
    if (this != &other) {
        clear();
        buckets_ = std::move(other.buckets_);
        size_ = other.size_;
        max_load_factor_ = other.max_load_factor_;

        other.size_ = 0;
        other.max_load_factor_ = DEFAULT_MAX_LOAD_FACTOR;
    }

    return *this;
}

template<typename Key, typename Value>
HashTable<Key, Value> &HashTable<Key, Value>::operator=(std::initializer_list<std::pair<Key, Value>> init_list) {
    clear();
    for (const auto &pair: init_list) {
        insert(pair.first, pair.second);
    }
    return *this;
}

template<typename Key, typename Value>
bool HashTable<Key, Value>::operator==(const HashTable &other) const {
    if (size_ != other.size_) return false;

    for (const auto &bucket: buckets_) {
        for (const auto &pair: bucket) {
            try {
                if (other.at(pair.first) != pair.second) {
                    return false;
                }
            } catch (const std::out_of_range &) {
                return false;
            }
        }
    }

    return true;
}

template<typename Key, typename Value>
bool HashTable<Key, Value>::operator!=(const HashTable &other) const {
    return !(*this == other);
}
