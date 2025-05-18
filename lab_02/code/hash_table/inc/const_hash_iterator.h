#pragma once

#include <list>
#include <memory>
#include <vector>

#include "base_iterator.h"
#include "exception.h"

template<typename Key, typename Value>
class HashTable;

template<typename Key, typename Value>
class HashTableConstIterator : public BaseIterator {
public:
    using NodeIterator = typename std::list<std::pair<Key, Value>>::const_iterator;

    explicit HashTableConstIterator(const HashTable<Key, Value> &hash_table);
    HashTableConstIterator(const HashTable<Key, Value> &hash_table, size_t bucket_idx, NodeIterator node_it);
    HashTableConstIterator(const HashTableConstIterator<Key, Value> &other);

    const std::pair<Key, Value> &operator*() const;
    const std::pair<Key, Value> *operator->() const;
    operator bool() const;

    const Key &getKey() const;
    const Value &getValue() const;

    HashTableConstIterator<Key, Value> &operator=(const HashTableConstIterator<Key, Value> &other);

    HashTableConstIterator<Key, Value> &operator++();  // префиксный
    HashTableConstIterator<Key, Value> operator++(int);// постфиксный
    HashTableConstIterator<Key, Value> &operator+=(int value);
    HashTableConstIterator<Key, Value> operator+(int value) const;

    HashTableConstIterator<Key, Value> &operator--();  // префиксный
    HashTableConstIterator<Key, Value> operator--(int);// постфиксный
    HashTableConstIterator<Key, Value> &operator-=(int value);
    HashTableConstIterator<Key, Value> operator-(int value) const;

    bool operator==(const HashTableConstIterator<Key, Value> &iterator) const;
    bool operator!=(const HashTableConstIterator<Key, Value> &iterator) const;
    bool operator<=(const HashTableConstIterator<Key, Value> &iterator) const;
    bool operator<(const HashTableConstIterator<Key, Value> &iterator) const;
    bool operator>=(const HashTableConstIterator<Key, Value> &iterator) const;
    bool operator>(const HashTableConstIterator<Key, Value> &iterator) const;

    bool isEnd() const;
    bool isValid() const;

private:
    void moveToLastElement();
    void moveToPreviousBucket();

    void checkValid() const;
    void checkNotEnd() const;

    std::weak_ptr<const HashTable<Key, Value>> table_ptr;
    size_t current_bucket = 0;
    NodeIterator current_node;
    size_t total_buckets = 0;
};

#include "const_hash_iterator.hpp"
