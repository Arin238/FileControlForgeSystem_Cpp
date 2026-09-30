//
// Created by Arin on 9/30/2026.
//
#include "HashMap.h"

template<typename T>
void Map<T>::NodeInsert(Node *a) {
    int idx = a->key % HASH;
    a->next = m_keys[idx];
    m_keys[idx] = a;
}

template<typename T>
void Map<T>::NodeDelete(int key) {
    int idx = key % HASH;
    Node *cur = m_keys[idx];
    Node *prev = nullptr;
    while (cur->key != key) {
        prev = cur;
        cur = cur->next;
    }
    if (prev == nullptr) {
        prev = cur->next;
        m_keys[idx] = prev;
    } else {
        prev->next = cur->next;
        delete cur;
    }
}

template<typename T>
T Map<T>::getKey(int key) {
    int idx = key % HASH;
    Node *cur = m_keys[idx];
    while (cur->key != key) {
        cur = cur->next;
    }
    return cur->value;
}

template<typename T>
bool Map<T>::isPresent(int key) {
    int idx = key % HASH;
    Node *cur = m_keys[idx];
    while (cur and cur->key != key) {
        cur = cur->next;
    }
    return (cur != nullptr);
}
