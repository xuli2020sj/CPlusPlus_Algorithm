//剑指 Offer II 062实现前缀树
//2022-06-19 20:24:05
/**
Trie（发音类似 "try"）或者说 前缀树 是一种树形数据结构，用于高效地存储和检索字符串数据集中的键。这一数据结构有相当多的应用情景，例如自动补完和拼写检
查。 

 请你实现 Trie 类： 

 
 Trie() 初始化前缀树对象。 
 void insert(String word) 向前缀树中插入字符串 word 。 
 boolean search(String word) 如果字符串 word 在前缀树中，返回 true（即，在检索之前已经插入）；否则，返回 false 。
 
 boolean startsWith(String prefix) 如果之前已经插入的字符串 word 的前缀之一为 prefix ，返回 true ；否则，
返回 false 。 
 

 

 示例： 

 
输入
inputs = ["Trie", "insert", "search", "search", "startsWith", "insert", 
"search"]
inputs = [[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
输出
[null, null, true, false, true, null, true]

解释
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // 返回 True
trie.search("app");     // 返回 False
trie.startsWith("app"); // 返回 True
trie.insert("app");
trie.search("app");     // 返回 True
 

 

 提示： 

 
 1 <= word.length, prefix.length <= 2000 
 word 和 prefix 仅由小写英文字母组成 
 insert、search 和 startsWith 调用次数 总计 不超过 3 * 10⁴ 次 
 

 

 

 注意：本题与主站 208 题相同：https://leetcode-cn.com/problems/implement-trie-prefix-tree/ 
 Related Topics 设计 字典树 哈希表 字符串 👍 22 👎 0

*/

#include "bits/stdc++.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)

struct xTreeNode {
    vector<xTreeNode *> child_node_{26};
    bool is_end_ = false;
    xTreeNode() = default;
};

class Trie {
public:
    xTreeNode root_node_{};
    /** Initialize your data structure here. */
    Trie() {};
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        xTreeNode * curr = &root_node_;
        for (char c: word) {
            int index = c - 'a';
            if (curr->child_node_[index] == nullptr) {
                curr->child_node_[index] = new xTreeNode();
            }
            curr = curr->child_node_[index];
        }
        curr->is_end_ = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        xTreeNode * curr = &root_node_;
        for (char c : word) {
            int index = c - 'a';
            if (curr->child_node_[index] == nullptr) {
                return false;
            } else {
                curr = curr->child_node_[index];
            }
        }
        return curr->is_end_;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        xTreeNode * curr = &root_node_;
        for (char c : prefix) {
            int index = c - 'a';
            if (curr->child_node_[index] == nullptr) {
                return false;
            } else {
                curr = curr->child_node_[index];
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    cout << "Hello" << endl;
}

