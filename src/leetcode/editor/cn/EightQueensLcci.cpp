//面试题 08.12八皇后
//2022-06-20 13:55:13
/**
设计一种算法，打印 N 皇后在 N × N 棋盘上的各种摆法，其中每个皇后都不同行、不同列，也不在对角线上。这里的“对角线”指的是所有的对角线，不只是平分整个棋
盘的那两条对角线。 

 注意：本题相对原题做了扩展 

 示例: 

  输入：4
 输出：[[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
 解释: 4 皇后问题存在如下两个不同的解法。
[
 [".Q..",  // 解法 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // 解法 2
  "Q...",
  "...Q",
  ".Q.."]
]
 
 Related Topics 数组 回溯 👍 149 👎 0

*/

#include "bits/stdc++.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isOk(vector<int>& queens, int row, int col) {
        int right_up = col + 1;
        int left_up = col - 1;
        for (int i = row-1; i >= 0; i--) {
            if (queens[i] == col) return false;
            if (right_up < queens.size() && queens[i] == right_up) return false;
            if (left_up >= 0 && queens[i] == left_up) return false;
            right_up++; left_up--;
        }
        return true;
    }

    void bakctrack(vector<vector<string>>& result, vector<int>& queens, int row, int n) {
        if (row == n) {
            result.push_back(generateBoard(queens));
            return ;
        }
        for (int col = 0; col < n; col++) {
            if (isOk(queens, row, col)) {
                queens[row] = col;
                bakctrack(result, queens, row+1, n);
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<int> queens(n);
        bakctrack(result, queens, 0, n);
        return result;
    }

    vector<string> generateBoard(vector<int> queens) {
        int n = queens.size();
        vector<string> result;
        for (int i = 0; i < n; i++) {
            string row(n, '.');
            row[queens[i]] = 'Q';
            result.push_back(row);
        }
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main() {
    Solution s;
    s.solveNQueens(8);
    cout << "Hello" << endl;
}
