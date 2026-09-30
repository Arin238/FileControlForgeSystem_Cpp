//
// Created by Arin on 9/30/2026.
//
#ifndef HEAP_H
#define HEAP_H
#include "HashMap.h"
const int MAX_CACHE_SIZE = 100;

struct Entry {
    int count;
    long long stamp;
    int key;
};

class Heap {
private:
    std::vector<Entry> m_heap;
    void heapifyUp();
    void heapifyDown();
    static bool before(const Entry &a, const Entry &b) {
        if (a.count != b.count)
            return a.count < b.count;
        return a.stamp < b.stamp;
    }

public:
    Heap() { m_heap.reserve(MAX_CACHE_SIZE); }
    void push(Entry e);
    void pop();
};
#endif // HEAP_H
