//733图像渲染
//2022-06-22 20:13:40
/**
有一幅以 m x n 的二维整数数组表示的图画 image ，其中 image[i][j] 表示该图画的像素值大小。 

 你也被给予三个整数 sr , sc 和 newColor 。你应该从像素 image[sr][sc] 开始对图像进行 上色填充 。 

 为了完成 上色工作 ，从初始像素开始，记录初始坐标的 上下左右四个方向上 像素值与初始坐标相同的相连像素点，接着再记录这四个方向上符合条件的像素点与他们对应 
四个方向上 像素值与初始坐标相同的相连像素点，……，重复该过程。将所有有记录的像素点的颜色值改为 newColor 。 

 最后返回 经过上色渲染后的图像 。 

 

 示例 1: 

 

 
输入: image = [[1,1,1],[1,1,0],[1,0,1]]，sr = 1, sc = 1, newColor = 2
输出: [[2,2,2],[2,2,0],[2,0,1]]
解析: 在图像的正中间，(坐标(sr,sc)=(1,1)),在路径上所有符合条件的像素点的颜色都被更改成2。
注意，右下角的像素没有更改为2，因为它不是在上下左右四个方向上与初始点相连的像素点。
 

 示例 2: 

 
输入: image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, newColor = 2
输出: [[2,2,2],[2,2,2]]
 

 

 提示: 

 
 m == image.length 
 n == image[i].length 
 1 <= m, n <= 50 
 0 <= image[i][j], newColor < 2¹⁶ 
 0 <= sr < m 
 0 <= sc < n 
 
 Related Topics 深度优先搜索 广度优先搜索 数组 矩阵 👍 340 👎 0

*/

#include "bits/stdc++.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    const int direction[4][2] {{1,0}, {0,1}, {-1, 0}, {0, -1}};
    void dfs(int x, int y, int target_color, int init_color, vector<vector<int>>& image) {
        if (x < 0 || x >= image.size() || y < 0 || y >= image[0].size() || image[x][y] != init_color) return ;
        image[x][y] = target_color;
        for (auto i : direction) {
            dfs(x+i[0], y+i[1], target_color, init_color, image);
        }
    }

    void bfs(int x, int y, int target_color, int init_color, vector<vector<int>>& image) {
        queue<pair<int, int>> queue1;
        queue1.push({x,y});
        while (!queue1.empty()) {
            int queue1_size = queue1.size();
            for (int i = 0; i < queue1_size; i++) {
                auto pos = queue1.front();
                image[pos.first][pos.second] = target_color;
                queue1.pop();
                for (auto d : direction) {
                    if (image[pos.first+d[0]][pos.second+d[1]] == init_color) {
                        queue1.push({pos.first+d[0], pos.second+d[1]});
                    }
                }
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int init_color = image[sr][sc];
        if (init_color != color) {
//            dfs(sr, sc, color, init_color, image);
            bfs(sr, sc, color, init_color, image);
        }
        return image;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    cout << "Hello" << endl;
}

