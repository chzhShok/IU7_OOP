#pragma once

#include "hash_table.h"

// TODO
template<typename Key, typename Value>
size_t HashTable<Key, Value>::hash(const Key &key) const noexcept {
    std::hash<Key> hasher;

    return hasher(key) % buckets_.size();// хэш-функция с модулем по количеству бакетов
}

template<typename Key, typename Value>
void HashTable<Key, Value>::checkAndRehash() {
    if (getLoadFactor() > max_load_factor_) {
        size_t new_bucket_count = next_power_of_two(buckets_.size() * 2);
        rehash(new_bucket_count);
    }
}

template<typename Key, typename Value>
typename HashTable<Key, Value>::Node *HashTable<Key, Value>::findNode(const Key &key) const {
    size_t index = hash(key);
    auto current = buckets_[index];
    while (current) {
        if (current->key == key)
            return current.get();

        current = current->next;
    }

    return nullptr;
}

template<typename Key, typename Value>
void HashTable<Key, Value>::deleteChain(Node *head) {
    while (head) {
        Node *temp = head;
        head = head->next.get();
        temp->next.reset();
    }
}

template<typename Key, typename Value>
size_t HashTable<Key, Value>::next_power_of_two(size_t n) noexcept {
    size_t power = 1;
    while (power < n) {
        power <<= 1;
    }
    return power;
}
