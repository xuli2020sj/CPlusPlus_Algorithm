#include <vector>
#include <iostream>
class Solution{
public:
    int getPath(std::vector<std::vector<int>>& nums){
        m = nums.size();
        n = nums[0].size();
        std::vector<std::vector<int>> visited(m, std::vector<int>(n,0));
        dfs(nums, 0, 0, 0, visited);
        return res;
    }
private:
    int m, n, res = INT_MAX, path = 0;

    void dfs(std::vector<std::vector<int>>& nums, int x, int y, int path, std::vector<std::vector<int>> visited){
        if(!isValid(x, y) || visited[x][y]) return;
        if(x == m - 1 && y == n - 1) {
            path += nums[x][y];
            res = std::min(path, res);
            return;
        }
        visited[x][y] = 1;
        dfs(nums, x, y + 1, path + nums[x][y], visited);
        dfs(nums, x + 1, y, path + nums[x][y], visited);
        dfs(nums, x, y - 1, path + nums[x][y], visited);
        dfs(nums, x - 1, y, path + nums[x][y], visited);
        visited[x][y] = 0;
    }
    bool isValid(int i, int j){
        if(i < 0 || i >= m || j < 0 || j >= n) return false;
        return true;
    }
};

int main(){
    Solution test;
    std::vector<std::vector<int>> nums{{1, 100, 1, 1, 1}, {1, 100, 1, 100, 1}, {1, 1, 1, 100, 1}};
    std::cout << test.getPath(nums);
}