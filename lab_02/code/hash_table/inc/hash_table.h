#pragma once

#include <vector>

#include "base_hash_table.h"
#include "const_hash_iterator.h"
#include "hash_iterator.h"

#define DEFAULT_MAX_LOAD_FACTOR 1.0

template<typename Key, typename Value>
class HashTable : public BaseHashTable {
public:
    explicit HashTable(size_t initial_size = 16);
    HashTable(size_t initial_size, double max_load_factor);
    HashTable(std::initializer_list<std::pair<Key, Value>> init_list);
    HashTable(const HashTable &other);
    HashTable(HashTable &&other) noexcept;
    ~HashTable() override = default;

    bool isEmpty() const noexcept override;
    size_t getSize() const noexcept override;
    double getLoadFactor() const noexcept override;
    double getMaxLoadFactor() const noexcept override;
    size_t getBucketCount() const noexcept override;

    void insert(const Key &key, const Value &value);
    bool remove(const Key &key);
    bool contains(const Key &key) const;
    void clear();
    void fill(HashTableIterator<Key, Value> start, const HashTableIterator<Key, Value> &end, const Value &value);
    void fill(HashTableIterator<Key, Value> start, HashTableIterator<Key, Value> source_start, const HashTableIterator<Key, Value> &source_end);
    void fill(HashTableIterator<Key, Value> start, HashTableConstIterator<Key, Value> source_start, const HashTableConstIterator<Key, Value> &source_end);

    void rehash(size_t new_bucket_count);
    void merge(const HashTable &other, std::function<Value(Value old_val, Value new_val)> resolveConflict = nullptr);

    HashTableIterator<Key, Value> begin() noexcept;
    HashTableIterator<Key, Value> end() noexcept;
    HashTableConstIterator<Key, Value> begin() const noexcept;
    HashTableConstIterator<Key, Value> end() const noexcept;
    HashTableConstIterator<Key, Value> cbegin() const noexcept;
    HashTableConstIterator<Key, Value> cend() const noexcept;

    Value &operator[](const Key &key);
    // в реализации unordered_map нет такого, так как подразумевается, что если ключа нет, что он добавляется
//    const Value &operator[](const Key &key) const;
    Value &at(const Key &key);
    const Value &at(const Key &key) const;

    HashTable &operator=(const HashTable &other);
    HashTable &operator=(HashTable &&other) noexcept;
    HashTable &operator=(std::initializer_list<std::pair<Key, Value>> init_list);
    bool operator==(const HashTable &other) const;
    bool operator!=(const HashTable &other) const;

private:
    struct Node {
        Key key;
        Value value;
        std::shared_ptr<Node> next;
    };

    size_t hash(const Key &key) const noexcept;
    void checkAndRehash();
    Node *findNode(const Key &key) const;
    void deleteChain(Node *head);
    size_t next_power_of_two(size_t n) noexcept;

    std::vector<std::shared_ptr<Node>> buckets_;
    size_t size_ = 0;
    double max_load_factor_ = DEFAULT_MAX_LOAD_FACTOR;
};

#include "hash_table_constructors.hpp"
