//662二叉树最大宽度
//2022-06-22 18:32:49
/**
给定一个二叉树，编写一个函数来获取这个树的最大宽度。树的宽度是所有层中的最大宽度。这个二叉树与满二叉树（full binary tree）结构相同，但一些节点为
空。 

 每一层的宽度被定义为两个端点（该层最左和最右的非空节点，两端点间的null节点也计入长度）之间的长度。 

 示例 1: 

 
输入: 

           1
         /   \
        3     2
       / \     \  
      5   3     9 

输出: 4
解释: 最大值出现在树的第 3 层，宽度为 4 (5,3,null,9)。
 

 示例 2: 

 
输入: 

          1
         /  
        3    
       / \       
      5   3     

输出: 2
解释: 最大值出现在树的第 3 层，宽度为 2 (5,3)。
 

 示例 3: 

 
输入: 

          1
         / \
        3   2 
       /        
      5      

输出: 2
解释: 最大值出现在树的第 2 层，宽度为 2 (3,2)。
 

 示例 4: 

 
输入: 

          1
         / \
        3   2
       /     \  
      5       9 
     /         \
    6           7
输出: 8
解释: 最大值出现在树的第 4 层，宽度为 8 (6,null,null,null,null,null,null,7)。
 

 注意: 答案在32位有符号整数的表示范围内。 
 Related Topics 树 深度优先搜索 广度优先搜索 二叉树 👍 374 👎 0

*/

#include "bits/stdc++.h"
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};



//leetcode submit region begin(Prohibit modification and deletion)

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        unsigned long result = 0;
        queue<pair<TreeNode*, unsigned long>> queue;
        queue.push({root, 1});
        while (!queue.empty()) {
            int queue_size = queue.size();
            unsigned long start = queue.front().second;
            unsigned long index;
            for (int i = 0; i < queue_size; i++) {
                TreeNode *curr = queue.front().first;
                index = queue.front().second;
                queue.pop();
                if (curr->left) queue.push({curr->left, index * 2 - 2 * start});
                if (curr->right) queue.push({curr->right, index * 2 + 1 - 2 * start});
            }
            result = max(result, index - start + 1);
        }
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    TreeNode t(1);
    TreeNode t1(3);
    TreeNode t2(2);
    TreeNode t3(5);
    TreeNode t4(3);
    TreeNode t5(9);
    t.left = &t1;
    t.right = &t2;
    t1.left = &t3;
    t1.right = &t4;
    t2.left = &t5;
    cout << s.widthOfBinaryTree(&t);
}