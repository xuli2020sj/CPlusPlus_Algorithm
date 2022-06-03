#include <vector>
#include <iostream>
class Solution{
public:
    int getPath(std::vector<std::vector<int>>& nums){
        m = nums.size();
        n = nums[0].size();
        dfs(nums, 0, 0);
        return res;
    }
private:
    int m, n, res = INT_MAX, path = 0;
    void dfs(std::vector<std::vector<int>>& nums, int x, int y){
        if(!isValid(x, y) || nums[x][y] < 0) return;
        if(x == m - 1 && y == n - 1) {
            path += nums[x][y];
            res = std::min(path, res);
            path -= nums[x][y];
            return;
        }
        path += nums[x][y];
        int tmp = nums[x][y];
        nums[x][y] = -1;
        dfs(nums, x, y + 1);
        dfs(nums, x + 1, y);
        dfs(nums, x - 1, y);
        dfs(nums, x, y - 1);
        path -= tmp;
        nums[x][y] = tmp;
    }
    bool isValid(int i, int j){
        if(i < 0 || i >= m || j < 0 || j >= n) return false;
        return true;
    }
};

int main(){
    Solution test;
    std::vector<std::vector<int>> nums{{1, 0, 1, 1, 1}, {1, 100, 1, 100, 1}, {1, 1, 1, 100, 3}};
    std::cout << test.getPath(nums);
}