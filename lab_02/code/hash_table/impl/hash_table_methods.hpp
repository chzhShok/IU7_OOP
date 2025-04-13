#pragma once

#include "hash_table.h"

template<typename Key, typename Value>
bool HashTable<Key, Value>::isEmpty() const noexcept {
    return size_ == 0;
}

template<typename Key, typename Value>
size_t HashTable<Key, Value>::getSize() const noexcept {
    return size_;
}

template<typename Key, typename Value>
double HashTable<Key, Value>::getLoadFactor() const noexcept {
    return buckets_.size() == 0 ? 0.0 : static_cast<double>(size_) / buckets_.size();
}

template<typename Key, typename Value>
double HashTable<Key, Value>::getMaxLoadFactor() const noexcept {
    return max_load_factor_;
}

template<typename Key, typename Value>
size_t HashTable<Key, Value>::getBucketCount() const noexcept {
    return buckets_.size();
}

template<typename Key, typename Value>
void HashTable<Key, Value>::clear() {
    for (auto &bucket: buckets_)
        bucket.clear();

    size_ = 0;
}

template<typename Key, typename Value>
void HashTable<Key, Value>::insert(const Key &key, const Value &value) {
    if (getLoadFactor() >= max_load_factor_)
        rehash(buckets_.size() * 2);

    size_t bucket_idx = hash(key) % buckets_.size();
    auto &bucket = buckets_[bucket_idx];

    for (auto &pair: bucket)
        if (pair.first == key) {
            pair.second = value;
            return;
        }

    bucket.emplace_back(key, value);

    ++size_;
}

template<typename Key, typename Value>
bool HashTable<Key, Value>::remove(const Key &key) {
    size_t bucket_idx = hash(key) % buckets_.size();
    auto &bucket = buckets_[bucket_idx];

    for (auto it = bucket.begin(); it != bucket.end(); ++it) {
        if (it->first == key) {
            bucket.erase(it);
            --size_;
            return true;
        }
    }

    return false;
}

template<typename Key, typename Value>
bool HashTable<Key, Value>::contains(const Key &key) const {
    size_t bucket_idx = hash(key) % buckets_.size();
    const auto &bucket = buckets_[bucket_idx];

    for (const auto &pair: bucket)
        if (pair.first == key)
            return true;

    return false;
}

template<typename Key, typename Value>
void HashTable<Key, Value>::rehash(size_t new_bucket_count) {
    if (new_bucket_count < size_ / max_load_factor_)
        new_bucket_count = std::ceil(size_ / max_load_factor_);

    std::vector<std::shared_ptr<Node>> new_buckets(new_bucket_count);

    for (auto &bucket: buckets_)
        for (auto &pair: bucket) {
            size_t new_bucket_idx = hash_function_(pair.first) % new_bucket_count;
            new_buckets[new_bucket_idx].push_back(std::move(pair));
        }

    buckets_ = std::move(new_buckets);
}
