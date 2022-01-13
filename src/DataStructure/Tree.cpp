//
// Created by x on 2022/1/8.
//

#include <iostream>
#include "Tree.h"

using namespace std;

/**
 *
 * @param value 向二叉树中插入给定值
 */
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

/**
 *
 * @param _value 二叉树中查找给定值
 * @return
 */
bool datastructure::Tree::find(int _value) {
    auto current = root;
    while (current != nullptr) {
        if(current->val > _value) {
            current = current->left_child;
        } else if (current->val < _value) {
            current = current->right_child;
        } else {
            return true;
        }
    }
    return false;
}

/**
 * @brief 前序遍历
 */
void datastructure::Tree::preOrderTraverse() {
    preOrderTraverse(root);
}

void datastructure::Tree::preOrderTraverse(datastructure::TreeNode*node) {
    if (node == nullptr) return;
    cout << node->val << " ";
    preOrderTraverse(node->left_child);
    preOrderTraverse(node->right_child);
}
int datastructure::Tree::height(datastructure::TreeNode *node) {
    if(node == nullptr) return 0;
    return 1 + max(height(node->left_child), height(node->right_child));
}

int datastructure::Tree::height() {
    return height(root);
}

/**
 *
 * @param node
 * @return true for leaf node
 */
bool datastructure::Tree::isLeaf(datastructure::TreeNode *node) {
    return !node->right_child && !node->left_child;
}
int datastructure::Tree::minVal() {
    return minVal(root);
}
int datastructure::Tree::minVal(datastructure::TreeNode *node) {
    if (isLeaf(node)) return node->val;
    auto left = node->left_child->val;
    auto right = node->right_child->val;
    return min(min(left, right), node->val);
}

/**
 *
 * @param other
 * @return true for equal
 */
bool datastructure::Tree::equals(datastructure::Tree &other) {
    return equals(root, other.root);
}
bool datastructure::Tree::equals(datastructure::TreeNode *first, datastructure::TreeNode *second) {
    if (first == nullptr && second == nullptr) return true;
    if (first != nullptr && second != nullptr) return first->val == second->val
                                                      && equals(first->right_child, second->right_child)
                                                      && equals(first->left_child, second->left_child);
    return false;
}

bool datastructure::Tree::isBinarySearchTree(datastructure::TreeNode *node, int min, int max) {
    if (node == nullptr) return true;
    if (node->val < min || node->val > max) return false;
    return isBinarySearchTree(node->right_child, node->val, max)
            && isBinarySearchTree(node->left_child, min, node->val);
}

bool datastructure::Tree::isBinarySearchTree() {
    return isBinarySearchTree(root, INT32_MIN, INT32_MAX);
}
std::vector<int> datastructure::Tree::nodesAtKDistance(int k) {
    vector<int> vec;
    nodeAtKDistance(root, k, vec);
    return vec;
}
void datastructure::Tree::nodeAtKDistance(datastructure::TreeNode *node, int Distance, std::vector<int> vec) {
    if (node == nullptr) return;
    if (Distance == 0) vec.push_back(node->val);
    nodeAtKDistance(node->left_child, Distance-1, vec);
    nodeAtKDistance(node->right_child, Distance-1, vec);
}
void datastructure::Tree::levelOrderTraversal(datastructure::TreeNode *node) {
    //TODO
}
