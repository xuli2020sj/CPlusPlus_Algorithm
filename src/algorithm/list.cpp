//
// Created by x on 2022/2/22.
//

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    explicit ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    static ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr) return nullptr;
        ListNode* curr = head;
        for (int i = 0; i < k -1; i++) {
            if (curr->next == nullptr) return head;
            curr = curr->next;
        }
        // ListNode* b = curr->next;
        ListNode* newHead = reverse1(head, curr);
        // head->next = reverseKGroup(b, k);
        return newHead;

    }

    static ListNode* reverse1(ListNode* l1, ListNode* l2) {
        ListNode* curr = l1;
        ListNode* pre = nullptr;
        ListNode* next = nullptr;
        while (curr != l2) {
            next = curr->next;
            curr->next = pre;
            pre = curr;
            curr = next;
        }
        return curr;
    }
};

int main() {
    auto* node1 = new ListNode(1);
    auto* node2 = new ListNode(2);
    auto* node3 = new ListNode(3);
    auto* node4 = new ListNode(4);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    auto s = new Solution;
    auto c =s->reverseKGroup(node1, 4);
    while (c) {
        std::cout << c->val;
        c = c->next;
    }
}