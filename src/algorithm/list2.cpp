#include <iostream>

template <typename T>
struct ListNode {
    ListNode<T>* pre;
    ListNode<T>* next;
    T data;
    ListNode(ListNode<T>* pre, ListNode<T> next, T data) : pre(nullptr), next(nullptr) {}
};

