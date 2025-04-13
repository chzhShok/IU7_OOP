#pragma once

#include <vector>

#include "base_hash_table.h"
#include "const_hash_iterator.h"
#include "hash_iterator.h"

template<typename Key, typename Value>
class HashTable : BaseHashTable {
public:
    friend class HashTable<Key, Value>;

    explicit HashTable(size_t initial_size = 16);
    HashTable(size_t initial_size, double max_load_factor);
    HashTable(std::initializer_list<std::pair<Key, Value>> init_list);
    HashTable(const HashTable &other);
    HashTable(HashTable &&other) noexcept;
    ~HashTable() override = default;

    // Базовые методы
    bool isEmpty() const noexcept override;
    size_t getSize() const noexcept override;
    double getLoadFactor() const noexcept override;
    double getMaxLoadFactor() const noexcept override;
    size_t getBucketCount() const noexcept override;

    // Основные операции
    void insert(const Key &key, const Value &value);
    bool remove(const Key &key);
    bool contains(const Key &key) const;
    void clear();
    void fill(Iterator<T> start, const Iterator<T> &end, const T &value);                           //TODO
    void fill(Iterator<T> start, Iterator<T> source_start, const Iterator<T> &source_end);          //TODO
    void fill(Iterator<T> start, ConstIterator<T> source_start, const ConstIterator<T> &source_end);//TODO

    // Рехеширование
    void rehash(size_t new_bucket_count);

    HashTable operator+(const HashTable &other) const;//TODO
    HashTable operator-(const HashTable &other) const;//TODO
    HashTable operator*(const HashTable &other) const;//TODO
    HashTable &operator+=(const HashTable &other);    //TODO
    HashTable &operator-=(const HashTable &other);    //TODO
    HashTable &operator*=(const HashTable &other);    //TODO

    HashTable operator+(const Value &value) const;//TODO
    HashTable operator-(const Value &value) const;//TODO
    HashTable operator*(const Value &value) const;//TODO
    HashTable operator/(const Value &value) const;//TODO
    HashTable &operator+=(const Value &value);    //TODO
    HashTable &operator-=(const Value &value);    //TODO
    HashTable &operator*=(const Value &value);    //TODO
    HashTable &operator/=(const Value &value);    //TODO

    HashTableIterator<Key, Value> begin() noexcept;            //TODO
    HashTableIterator<Key, Value> end() noexcept;              //TODO
    HashTableConstIterator<Key, Value> begin() const noexcept; //TODO
    HashTableConstIterator<Key, Value> end() const noexcept;   //TODO
    HashTableConstIterator<Key, Value> cbegin() const noexcept;//TODO
    HashTableConstIterator<Key, Value> cend() const noexcept;  //TODO

    Value &operator[](const Key &key);            //TODO
    const Value &operator[](const Key &key) const;//TODO
    Value &at(const Key &key);                    //TODO
    const Value &at(const Key &key) const;        //TODO
    //    T &operator()(int rows_size, int columns_size);//TODO
    //    const T &operator()(int rows_size, int columns_size) const;//TODO

    HashTable &operator=(const HashTable &other);                                //TODO
    HashTable &operator=(HashTable &&other) noexcept;                            //TODO
    HashTable &operator=(std::initializer_list<std::pair<Key, Value>> init_list);//TODO
    bool operator==(const HashTable &other) const;                               //TODO
    bool operator!=(const HashTable &other) const;                               //TODO

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

    //TODO
    std::vector<std::shared_ptr<Node>> buckets_;
    size_t size_ = 0;
    double max_load_factor_ = 1.0;
};

#include "hash_table_constructors.hpp"
