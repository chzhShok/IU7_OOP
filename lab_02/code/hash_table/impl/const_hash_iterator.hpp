#pragma once

#include "const_hash_iterator.h"

//TODO
template<typename Key, typename Value>
HashTableConstIterator<Key, Value>::HashTableConstIterator(const HashTable<Key, Value> &hash_table)
    : table_ptr(&hash_table),
      current_bucket(0),
      total_buckets(hash_table.getBucketCount()) {

    if (hash_table.isEmpty()) {
        current_bucket = total_buckets;
    } else {
        for (; current_bucket < total_buckets; ++current_bucket) {
            auto &bucket = table_ptr->buckets[current_bucket];
            if (!bucket.empty()) {
                current_node = bucket.begin();
                return;
            }
        }
    }

    current_bucket = total_buckets;
}

//TODO
template<typename Key, typename Value>
HashTableConstIterator<Key, Value>::HashTableConstIterator(const HashTable<Key, Value> &hash_table, size_t bucket_idx, NodeIterator node_it)
    : table_ptr(&hash_table),
      current_bucket(bucket_idx),
      current_node(node_it),
      total_buckets(hash_table.getBucketCount()) {
    if (bucket_idx >= total_buckets) {
        current_bucket = total_buckets;
    }
}

template<typename Key, typename Value>
HashTableConstIterator<Key, Value>::HashTableConstIterator(const HashTableConstIterator<Key, Value> &other)
    : table_ptr(other.table_ptr),
      current_bucket(other.current_bucket),
      current_node(other.current_node),
      total_buckets(other.total_buckets) {
}

//TODO
template<typename Key, typename Value>
const std::pair<Key, Value> &HashTableConstIterator<Key, Value>::operator*() const {
    checkNotEnd();
    checkValid();
    return *current_node;
}

//TODO
template<typename Key, typename Value>
const std::pair<Key, Value> *HashTableConstIterator<Key, Value>::operator->() const {
    checkNotEnd();
    checkValid();

    return &(*current_node);
}

template<typename Key, typename Value>
HashTableConstIterator<Key, Value>::operator bool() const {
    return table_ptr &&
           current_bucket < total_buckets &&
           current_node != table_ptr->buckets[current_bucket].end();
}

template<typename Key, typename Value>
const Key &HashTableConstIterator<Key, Value>::getKey() const {
    checkNotEnd();
    checkValid();

    return current_node->first;
}

template<typename Key, typename Value>
const Value &HashTableConstIterator<Key, Value>::getValue() const {
    checkNotEnd();
    checkValid();
    return current_node->second;
}

template<typename Key, typename Value>
HashTableConstIterator<Key, Value> &HashTableConstIterator<Key, Value>::operator=(const HashTableConstIterator<Key, Value> &other) {
    if (this != &other) {
        table_ptr = other.table_ptr;
        current_bucket = other.current_bucket;
        current_node = other.current_node;
        total_buckets = other.total_buckets;
    }

    return *this;
}

template<typename Key, typename Value>
HashTableConstIterator<Key, Value> &HashTableConstIterator<Key, Value>::operator++() {
    if (current_bucket >= total_buckets) {
        time_t currentTime = time(NULL);
        throw IndexError(__FILE__, typeid(*this).name(), __LINE__, ctime(&currentTime));
    }

    ++current_node;

    if (current_node == table_ptr->buckets[current_bucket].end()) {
        for (++current_bucket; current_bucket < total_buckets; ++current_bucket) {
            if (!table_ptr->buckets[current_bucket].empty()) {
                current_node = table_ptr->buckets[current_bucket].begin();
                return *this;
            }
        }

        current_bucket = total_buckets;
    }

    return *this;
}

template<typename Key, typename Value>
HashTableConstIterator<Key, Value> HashTableConstIterator<Key, Value>::operator++(int) {
    HashTableConstIterator<Key, Value> tmp(*this);
    ++(*this);
    return tmp;
}

template<typename Key, typename Value>
HashTableConstIterator<Key, Value> &HashTableConstIterator<Key, Value>::operator+=(int value) {
    if (value < 0) {
        time_t currentTime = time(NULL);
        throw NegativeIncrement(__FILE__, typeid(*this).name(), __LINE__, ctime(&currentTime));
    }

    while (value-- > 0)
        ++(*this);

    return *this;
}

template<typename Key, typename Value>
HashTableConstIterator<Key, Value> HashTableConstIterator<Key, Value>::operator+(int value) const {
    HashTableConstIterator<Key, Value> tmp(*this);
    tmp += value;
    return tmp;
}

template<typename Key, typename Value>
HashTableConstIterator<Key, Value> &HashTableConstIterator<Key, Value>::operator--() {
    if (current_bucket >= total_buckets) {
        moveToLastElement();
        return *this;
    }

    if (current_node == table_ptr->buckets[current_bucket].begin())
        moveToPreviousBucket();
    else
        --current_node;

    return *this;
}

template<typename Key, typename Value>
HashTableConstIterator<Key, Value> HashTableConstIterator<Key, Value>::operator--(int) {
    HashTableConstIterator<Key, Value> tmp(*this);
    --(*this);
    return tmp;
}

template<typename Key, typename Value>
HashTableConstIterator<Key, Value> &HashTableConstIterator<Key, Value>::operator-=(int value) {
    if (value < 0) {
        return *this += (-value);
    }

    while (value-- > 0) {
        --(*this);
    }

    return *this;
}

template<typename Key, typename Value>
HashTableConstIterator<Key, Value> HashTableConstIterator<Key, Value>::operator-(int value) const {
    HashTableConstIterator<Key, Value> tmp(*this);
    tmp -= value;
    return tmp;
}

//TODO
template<typename Key, typename Value>
bool HashTableConstIterator<Key, Value>::operator==(const HashTableConstIterator<Key, Value> &other) const {
    if (current_bucket >= total_buckets && other.current_bucket >= other.total_buckets)
        return true;

    if (table_ptr != other.table_ptr || current_bucket >= total_buckets || other.current_bucket >= other.total_buckets)
        return false;

    return current_bucket == other.current_bucket && current_node == other.current_node;
}

template<typename Key, typename Value>
bool HashTableConstIterator<Key, Value>::operator!=(const HashTableConstIterator<Key, Value> &other) const {
    return !(*this == other);
}

template<typename Key, typename Value>
bool HashTableConstIterator<Key, Value>::operator<(const HashTableConstIterator<Key, Value> &other) const {
    if (table_ptr != other.table_ptr)
        return false;

    if (current_bucket >= total_buckets)
        return false;
    if (other.current_bucket >= other.total_buckets)
        return true;

    if (current_bucket != other.current_bucket)
        return current_bucket < other.current_bucket;

    auto &bucket = table_ptr->buckets[current_bucket];
    for (auto it = bucket.begin(); it != bucket.end(); ++it) {
        if (it == other.current_node)
            return false;
        if (it == current_node)
            return true;
    }
    return false;
}

template<typename Key, typename Value>
bool HashTableConstIterator<Key, Value>::operator<=(const HashTableConstIterator<Key, Value> &other) const {
    return *this < other || *this == other;
}

template<typename Key, typename Value>
bool HashTableConstIterator<Key, Value>::operator>(const HashTableConstIterator<Key, Value> &other) const {
    return !(*this <= other);
}

template<typename Key, typename Value>
bool HashTableConstIterator<Key, Value>::operator>=(const HashTableConstIterator<Key, Value> &other) const {
    return !(*this < other);
}

template<typename Key, typename Value>
bool HashTableConstIterator<Key, Value>::isEnd() const {
    return current_bucket >= total_buckets || total_buckets == 0;
}

//TODO
template<typename Key, typename Value>
bool HashTableConstIterator<Key, Value>::isValid() const {
    if (!table_ptr || isEnd())
        return false;

    auto &bucket = table_ptr->buckets[current_bucket];
    for (auto it = bucket.begin(); it != bucket.end(); ++it)
        if (it == current_node)
            return true;

    return false;
}

//TODO
template<typename Key, typename Value>
void HashTableConstIterator<Key, Value>::moveToLastElement() {
    if (!table_ptr || total_buckets == 0) {
        time_t currentTime = time(NULL);
        throw IndexError(__FILE__, typeid(*this).name(), __LINE__, ctime(&currentTime));
    }

    for (current_bucket = total_buckets - 1;; --current_bucket) {
        auto &bucket = table_ptr->buckets[current_bucket];
        if (!bucket.empty()) {
            current_node = --bucket.end();
            return;
        }

        if (current_bucket == 0)
            break;
    }

    time_t currentTime = time(NULL);
    throw IndexError(__FILE__, typeid(*this).name(), __LINE__, ctime(&currentTime));
}

//TODO
template<typename Key, typename Value>
void HashTableConstIterator<Key, Value>::moveToPreviousBucket() {
    while (current_bucket > 0) {
        --current_bucket;
        auto &bucket = table_ptr->buckets[current_bucket];

        if (!bucket.empty()) {
            current_node = --bucket.end();
            return;
        }
    }

    time_t currentTime = time(NULL);
    throw IndexError(__FILE__, typeid(*this).name(), __LINE__, ctime(&currentTime));
}

template<typename Key, typename Value>
void HashTableConstIterator<Key, Value>::checkNotEnd() const {
    if (current_bucket >= total_buckets) {
        time_t currentTime = time(NULL);
        throw IndexError(__FILE__, typeid(*this).name(), __LINE__, ctime(&currentTime));
    }
}

template<typename Key, typename Value>
void HashTableConstIterator<Key, Value>::checkValid() const {
    if (current_node == table_ptr->buckets[current_bucket].end()) {
        time_t currentTime = time(NULL);
        throw InvalidIterator(__FILE__, typeid(*this).name(), __LINE__, ctime(&currentTime));
    }
}
