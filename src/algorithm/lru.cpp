#include <iostream>
#include <unordered_map>

using namespace std;

struct DLinkedNode {
    int key, value;
    DLinkedNode* pre;
    DLinkedNode* next;
    DLinkedNode() : key(0), value(0), pre(nullptr), next(nullptr) {}
    DLinkedNode(int key, int val) : key(key), value(val), pre(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    unordered_map<int, DLinkedNode*> cache;
    DLinkedNode* head;
    DLinkedNode* tail;
    int capacity;
    int size;

    void move_to_head(DLinkedNode* node) {
        node->pre->next = node->next;
        node->next->pre = node->pre;
        add_to_head(node);
    }

    void delete_node(DLinkedNode* node) {
        node->pre->next = node->next;
        node->next->pre = node->pre;
        cache.erase(node->key);
        delete node;
        size--;
    }

    void add_to_head(DLinkedNode* node) {
        node->pre = head;
        node->next = head->next;
        head->next = node;
        node->next->pre = node;
    }

public:
    LRUCache(int capacity) : capacity(capacity), size(0) {
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->pre = head;
    }

    int get(int key) {
        auto pair = cache.find(key);
        if (pair == cache.end()) {
            return -1;
        } else {
            move_to_head(pair->second);
            return pair->second->value;
        }
    }

    void put(int key, int value) {
        auto pair = cache.find(key);
        if (pair == cache.end()) {
            if (size == capacity) {
                delete_node(tail->pre);
            }
            cache[key] = new DLinkedNode(key, value);
            add_to_head(cache[key]);
            size++;
        } else {
            // update data
            pair->second->value = value;
            move_to_head(pair->second);
        };
    }
};

int main() {
    auto c = new LRUCache(3);
    c->put(1,1);
    c->put(2,1);
    c->put(1,1);
    cout << c->get(1);
}


