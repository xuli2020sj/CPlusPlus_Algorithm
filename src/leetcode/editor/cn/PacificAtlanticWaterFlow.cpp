//有一个 m × n 的矩形岛屿，与 太平洋 和 大西洋 相邻。 “太平洋” 处于大陆的左边界和上边界，而 “大西洋” 处于大陆的右边界和下边界。 
//
// 这个岛被分割成一个由若干方形单元格组成的网格。给定一个 m x n 的整数矩阵 heights ， heights[r][c] 表示坐标 (r, c) 上
//单元格 高于海平面的高度 。 
//
// 岛上雨水较多，如果相邻单元格的高度 小于或等于 当前单元格的高度，雨水可以直接向北、南、东、西流向相邻单元格。水可以从海洋附近的任何单元格流入海洋。 
//
// 返回网格坐标 result 的 2D 列表 ，其中 result[i] = [ri, ci] 表示雨水从单元格 (ri, ci) 流动 既可流向太平洋也可
//流向大西洋 。 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入: heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
//输出: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
// 
//
// 示例 2： 
//
// 
//输入: heights = [[2,1],[1,2]]
//输出: [[0,0],[0,1],[1,0],[1,1]]
// 
//
// 
//
// 提示： 
//
// 
// m == heights.length 
// n == heights[r].length 
// 1 <= m, n <= 200 
// 0 <= heights[r][c] <= 10⁵ 
// 
// Related Topics 深度优先搜索 广度优先搜索 数组 矩阵 👍 482 👎 0


#include <bits/stdc++.h>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)

static const int directions[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
class Solution {
private:
    size_t rows;
    size_t cols;
public:
    void dfs(size_t row, size_t col, vector<vector<bool>>& ocean, vector<vector<int>>& heights) {
        if (ocean[row][col]) return ;
        ocean[row][col] = true;
        for (int i = 0; i < 4; i++) {
            size_t nextRow = row + directions[i][0];
            size_t nextCol = col + directions[i][1];
            if (nextCol >= 0 && nextCol < cols && nextRow >= 0 && nextRow < rows && heights[nextRow][nextCol] >= heights[row][col]) dfs(nextRow, nextCol, ocean, heights);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        rows = heights.size();
        cols = heights[0].size();
        vector<vector<bool>> pacific(rows, vector<bool>(cols, false));
        vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));
        for (size_t i = 0; i < cols; i++) dfs(0, i, pacific, heights);
        for (size_t j = 0; j < rows; j++) dfs(j, 0, pacific, heights);
        for (size_t i = 0; i < cols; i++) dfs(rows-1, i, atlantic, heights);
        for (size_t j = 0; j < rows; j++) dfs(j, cols-1, atlantic, heights);
        vector<vector<int>> res;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)




int main() {
    
}

