//498对角线遍历
//2022-06-14 11:10:45
/**
给你一个大小为 m x n 的矩阵 mat ，请以对角线遍历的顺序，用一个数组返回这个矩阵中的所有元素。 

 

 示例 1： 

 
输入：mat = [[1,2,3],[4,5,6],[7,8,9]]
输出：[1,2,4,7,5,3,6,8,9]
 

 示例 2： 

 
输入：mat = [[1,2],[3,4]]
输出：[1,2,3,4]
 

 

 提示： 

 
 m == mat.length 
 n == mat[i].length 
 1 <= m, n <= 10⁴ 
 1 <= m * n <= 10⁴ 
 -10⁵ <= mat[i][j] <= 10⁵ 
 
 Related Topics 数组 矩阵 模拟 👍 327 👎 0

*/

#include "bits/stdc++.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int col = mat.size();
        int row = mat[0].size();
        if (col == 0) return {};
        vector<int> res;
        int flag = 1;
        for (int i = 0; i < col + row-2; i++) {
            if (flag > 0) {

                for(int j = 0; j <= i; j++) {
                    res.push_back(mat[j][i-j]);
                }
            } else {
                for (int j = i; j >= 0; j--) {
                    res.push_back(mat[j][i-j]);
                }
            }
            flag *= -1;
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<vector<int>> mat{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    s.findDiagonalOrder(mat);
}

