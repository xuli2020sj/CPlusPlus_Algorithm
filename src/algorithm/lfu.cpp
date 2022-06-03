#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key, val;
    size_t frequency;
    size_t time;

    bool operator < (const Node& rhs) const {
        return frequency == rhs.frequency ? time < rhs.time : frequency < rhs.frequency;
    }

    Node(int _frequency, int _key, int _val, size_t _time) : key(_key), frequency(_frequency), val(_val), time(_time) {}
};

class LFUCache {
private:
    size_t capacity;
    size_t time;
    unordered_map<int, Node> cache;
    set<Node> s;
public:
    explicit LFUCache(int capacity) : capacity(capacity), time(0) {
    }

    int get(int key) {
        auto iter = cache.find(key);
        if (iter == cache.end()) {
            return -1;
        } else {
            Node temp = iter->second;
            s.erase(temp);
            temp.frequency++;
            temp.time = ++time;
            s.insert(temp);
            return temp.val;
        }
    }

    void put(int key, int value) {
        if (capacity == 0) return;
        auto iter = cache.find(key);
        if (iter == cache.end()) {
            if (cache.size() == capacity) {
                cache.erase(s.begin()->key);
                s.erase(s.begin());
            }
            Node temp = Node(1, key, value, ++time);
            cache.insert(make_pair(key, temp));
            s.insert(temp);
        } else {
            Node temp = iter->second;
            s.erase(temp);
            temp.val = value;
            temp.frequency++;
            temp.time = ++time;
            s.insert(temp);
        }
    }
};



int main() {
    auto c = LFUCache(2);
    c.put(1,1);
    c.put(2,2);
    cout << c.get(1) << endl;
    c.put(3,3);
    cout <<c.get(2) << endl;
    cout <<c.get(3) << endl;
    c.put(4,4);
    cout <<c.get(1) << endl;
    cout <<c.get(3) << endl;
    cout << c.get(4) << endl;
}