#pragma once

#include "hash_table.h"

template<typename Key, typename Value>
HashTableIterator<Key, Value> HashTable<Key, Value>::begin() noexcept {
    for (size_t i = 0; i < buckets_.size(); ++i)
        if (!buckets_[i].empty())
            return HashTableIterator<Key, Value>(*this, i, buckets_[i].begin());

    return end();
}

template<typename Key, typename Value>
HashTableIterator<Key, Value> HashTable<Key, Value>::end() noexcept {
    return HashTableIterator<Key, Value>(
            *this,
            buckets_.size(),
            buckets_.empty() ? typename std::list<std::pair<Key, Value>>::iterator()
                             : buckets_.back().end());
}

template<typename Key, typename Value>
HashTableConstIterator<Key, Value> HashTable<Key, Value>::begin() const noexcept {
    for (size_t i = 0; i < buckets_.size(); ++i)
        if (!buckets_[i].empty())
            return HashTableConstIterator<Key, Value>(*this, i, buckets_[i].cbegin());

    return cend();
}

template<typename Key, typename Value>
HashTableConstIterator<Key, Value> HashTable<Key, Value>::end() const noexcept {
    return HashTableConstIterator<Key, Value>(
            *this,
            buckets_.size(),
            buckets_.empty() ? typename std::list<std::pair<Key, Value>>::const_iterator()
                             : buckets_.back().cend());
}

template<typename Key, typename Value>
HashTableConstIterator<Key, Value> HashTable<Key, Value>::cbegin() const noexcept {
    return begin();
}

template<typename Key, typename Value>
HashTableConstIterator<Key, Value> HashTable<Key, Value>::cend() const noexcept {
    return end();
}
