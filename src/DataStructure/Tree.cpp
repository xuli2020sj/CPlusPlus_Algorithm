//
// Created by x on 2022/1/8.
//

#include "Tree.h"


void datastructure::Tree::insert(int value) {
    auto node = new TreeNode(value);
    if (root == nullptr) {
        root = node;
        return;
    }
    auto current = this->root;
    while (true) {
        if (value > current->val) {
            if (current->right_child == nullptr) {
                current->right_child = node;
                break;
            }
            current = current->right_child;
        } else {
            if (current->left_child == nullptr) {
                current->left_child = node;
                break;
            }
            current = current->left_child;
        }
    }
}

datastructure::Tree::Tree() {
    root = nullptr;
}
