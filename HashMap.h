//
// Created by Arin on 9/30/2026.
//

#ifndef HASHMAP_H
#define HASHMAP_H
#include <vector>

const int HASH = 101;


struct Node {
    int key = -1;
    int value = -1;
    Node *next = nullptr;
    int counter{0};
    int stamp{-1};
};

template<typename T>
class Map {
private:
    std::vector<Node *> m_keys;
    void NodeInsert(Node *a);
    void NodeDelete(int key);
    T getKey(int key);

public:
    Map() {
        m_keys.resize(HASH);
        for (int i = 0; i < HASH; i++) {
            m_keys[i] = new Node;
        }
    }
    void insert(int key, T value) {
        if (!isPresent(key)) {
            Node a = new Node{key, value, nullptr};
            NodeInsert(&a);
        }
    }
    void del(int key) {
        if (isPresent(key)) {
            NodeDelete(key);
        }
    }
    T get(int key) {
        if (isPresent(key))
            return getKey(key);
        else
            return -1;
    }
    bool isPresent(int key);
};

#endif // HASHMAP_H
