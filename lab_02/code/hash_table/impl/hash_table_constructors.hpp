#pragma once

#include "hash_table.h"

//TODO
template<typename Key, typename Value>
HashTable<Key, Value>::HashTable(size_t initial_size)
    : size_(0),
      max_load_factor_(1.0),
      buckets_(next_power_of_two(initial_size))// Переносим resize в инициализацию
{
    if (initial_size == 0) {
        time_t currentTime = time(nullptr);
        throw IndexError(__FILE__, typeid(*this).name(), __LINE__, ctime(&currentTime));
    }
}

template<typename Key, typename Value>
HashTable<Key, Value>::HashTable(size_t initial_size, double max_load_factor)
    : HashTable(initial_size) {
    if (max_load_factor <= 0 || max_load_factor > 2.0) {
        time_t currentTime = time(nullptr);
        throw InvalidMaxLoadFactor(__FILE__, typeid(*this).name(), __LINE__, ctime(&currentTime));
    }

    max_load_factor_ = max_load_factor;
}

template<typename Key, typename Value>
HashTable<Key, Value>::HashTable(std::initializer_list<std::pair<Key, Value>> init_list)
    : HashTable() {
    for (const auto &pair: init_list) {
        insert(pair.first, pair.second);
    }
}

template<typename Key, typename Value>
HashTable<Key, Value>::HashTable(const HashTable &other)
    : buckets_(other.buckets_.size()),
      size_(other.size_),
      max_load_factor_(other.max_load_factor_) {
    for (size_t i = 0; i < other.buckets_.size(); ++i)
        for (const auto &node: other.buckets_[i])
            buckets_[i].push_back(node);
}

template<typename Key, typename Value>
HashTable<Key, Value>::HashTable(HashTable &&other) noexcept
    : buckets_(std::move(other.buckets_)),
      size_(other.size_),
      max_load_factor_(other.max_load_factor_) {
}
