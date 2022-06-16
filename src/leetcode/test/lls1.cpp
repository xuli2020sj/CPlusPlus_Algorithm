#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* formatList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return head;
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* curr = head->next;
    ListNode* tail = head;
    int flag = -1;
    while (curr) {
        if (flag > 0) {
            ListNode* temp = dummy->next;
            ListNode* temp2 = curr->next;
            dummy->next = curr;
            curr->next = temp;
            curr = temp2;
        } else {
            tail->next = curr;
            curr = curr->next;
            tail = tail->next;
            tail->next = nullptr;

        }
        flag *= -1;
    }
    return dummy->next;
    // write code here
}

int main(){
    ListNode* l1 = new ListNode(1);
    ListNode* l2 = new ListNode(2);
    ListNode* l3 = new ListNode(3);
    ListNode* l4 = new ListNode(4);
    ListNode* l5 = new ListNode(5);
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;

    ListNode* head = formatList(l1);
    cout << "ok";
}