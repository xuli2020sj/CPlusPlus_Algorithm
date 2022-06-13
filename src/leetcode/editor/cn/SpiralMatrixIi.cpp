//59
//螺旋矩阵 II
//spiral-matrix-ii

//给你一个正整数 n ，生成一个包含 1 到 n² 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。 
//
// 
//
// 示例 1： 
//
// 
//输入：n = 3
//输出：[[1,2,3],[8,9,4],[7,6,5]]
// 
//
// 示例 2： 
//
// 
//输入：n = 1
//输出：[[1]]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= n <= 20 
// 
// Related Topics 数组 矩阵 模拟 👍 730 👎 0


#include <bits/stdc++.h>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int end = n * n;
        int count = 1;
        int row = 0, col = 0;
        int up_limit = 0, down_limit = n-1, left_limit = 0, right_limit = n-1;
        while (count <= end) {
            for (row = up_limit, col = left_limit; col <= right_limit && count <= end; col++) {
                res[row][col] = count;
                count++;
            }
            up_limit++;
            for (row = up_limit, col = right_limit; row <= down_limit && count <= end; row++) {
                res[row][col] = count;
                count++;
            }
            right_limit--;
            for (row = down_limit, col = right_limit; col >= left_limit && count <= end; col--) {
                res[row][col] = count;
                count++;
            }
            down_limit--;
            for (row = down_limit, col = left_limit; row >= up_limit && count <= end; row--) {
                res[row][col] = count;
                count++;
            }
            left_limit++;
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)




int main() {
    Solution s;
    auto a = s.generateMatrix(4);
    cout << "j";
}

