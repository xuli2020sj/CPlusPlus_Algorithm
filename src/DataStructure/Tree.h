//
// Created by x on 2022/1/8.
//

#ifndef CPLUSPLUS_ALGORITHM_TREE_H
#define CPLUSPLUS_ALGORITHM_TREE_H

#include <utility>
#include <vector>


namespace datastructure {

struct TreeNode {
    int val;
    TreeNode* right_child;
    TreeNode* left_child;
    explicit TreeNode(int _val) : val(_val), right_child(nullptr), left_child(nullptr) {};
};

class Tree {
private:
    TreeNode* root;
public:
    Tree();
    void insert(int value);
    bool find(int _value);

    void levelOrderTraversial();
    void preOrderTraverse();
    int height();
    int minVal();
    bool equals(Tree &other);
    bool isBinarySearchTree();
    std::vector<int> nodesAtKDistance(int k);

private:
    int height(TreeNode*node);

    void preOrderTraverse(TreeNode* node);
    void levelOrderTraversal(TreeNode* node);

    static int minVal(TreeNode* node);
    static bool isLeaf(TreeNode* node);
    bool equals(TreeNode* first, TreeNode* second);
    bool isBinarySearchTree(TreeNode* node, int min, int max);
    void nodeAtKDistance(TreeNode*node, int Distance, std::vector<int> vec);

};

}

#endif //CPLUSPLUS_ALGORITHM_TREE_H
