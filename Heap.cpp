//
// Created by Arin on 9/30/2026.
//
#include "Heap.h"
void Heap::push(Entry e) {
    m_heap.push_back(e);
    heapifyUp();
}

void Heap::pop() {
    std::swap(m_heap.front(), m_heap.back());
    m_heap.pop_back();
    if (!m_heap.empty())
        heapifyDown();
}

void Heap::heapifyUp() {
    size_t cur = m_heap.size() - 1;
    while (cur > 0) {
        size_t par = (cur - 1) / 2;
        if (!before(m_heap[cur], m_heap[par]))
            break;
        std::swap(m_heap[cur], m_heap[par]);
        par = cur;
    }
}

void Heap::heapifyDown() {
    size_t cur = 0, n = m_heap.size();
    while (true) {
        size_t l = 2 * cur + 1, r = l + 1, best = cur;
        if (l < n and before(m_heap[best], m_heap[l])) {
            best = l;
        }
        if (r < n and before(m_heap[best], m_heap[r])) {
            best = r;
        }
        if (best == cur)
            break;
        std::swap(m_heap[cur], m_heap[best]);
        cur = best;
    }
}
