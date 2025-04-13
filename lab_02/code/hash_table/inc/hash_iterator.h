#pragma once

#include <list>
#include <memory>

#include "base_iterator.h"
#include "exception.h"

template<typename Key, typename Value>
class HashTable;

template<typename Key, typename Value>
class HashTableIterator : public BaseIterator {
public:
    using NodeIterator = typename std::list<std::pair<Key, Value>>::iterator;

    HashTableIterator() = default;
    explicit HashTableIterator(HashTable<Key, Value> &hash_table);
    HashTableIterator(HashTable<Key, Value> &hash_table, size_t bucket_idx, NodeIterator node_it);
    HashTableIterator(const HashTableIterator<Key, Value> &other);

    std::pair<Key, Value> &operator*();
    const std::pair<Key, Value> &operator*() const;
    std::pair<Key, Value> *operator->();
    const std::pair<Key, Value> *operator->() const;
    operator bool() const;

    Key &getKey();
    const Key &getKey() const;
    Value &getValue();
    const Value &getValue() const;

    HashTableIterator<Key, Value> &operator=(const HashTableIterator<Key, Value> &other);

    HashTableIterator<Key, Value> &operator++();  // префиксный
    HashTableIterator<Key, Value> operator++(int);// постфиксный
    HashTableIterator<Key, Value> &operator+=(int value);
    HashTableIterator<Key, Value> operator+(int value) const;

    HashTableIterator<Key, Value> &operator--();  // префиксный
    HashTableIterator<Key, Value> operator--(int);// постфиксный
    HashTableIterator<Key, Value> &operator-=(int value);
    HashTableIterator<Key, Value> operator-(int value) const;

    bool operator==(const HashTableIterator<Key, Value> &iterator) const;
    bool operator!=(const HashTableIterator<Key, Value> &iterator) const;
    bool operator<=(const HashTableIterator<Key, Value> &iterator) const;
    bool operator<(const HashTableIterator<Key, Value> &iterator) const;
    bool operator>=(const HashTableIterator<Key, Value> &iterator) const;
    bool operator>(const HashTableIterator<Key, Value> &iterator) const;

    bool isEnd() const;
    bool isValid() const;

private:
    void moveToLastElement();
    void moveToPreviousBucket();

    void checkValid() const;
    void checkNotEnd() const;

    std::weak_ptr<HashTable<Key, Value>> table_ptr;
    size_t current_bucket = 0;
    NodeIterator current_node;
    size_t total_buckets = 0;
};

#include "hash_iterator.hpp"
