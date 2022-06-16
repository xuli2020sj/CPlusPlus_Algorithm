#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param a int整型vector
     * @return long长整型
     */
    long long minimum(vector<int>& a) {
        int n = a.size();
        vector<int> preSum(n+1, 0);
        for (int i = 1; i <= n; i++) {
            preSum[i] = preSum[i-1] + a[i-1];
        }
        long long sum = preSum[n];
        long long ans = LONG_LONG_MAX;
        for (int i = 0; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                if (j-i == n) continue;
                long long temp = a[j] - a[i];
                temp = abs(sum - 2 * temp);
                ans = min(temp, ans);
            }
        }
        return ans;
    }
};

int main(){
    Solution solution;
    vector<int> v = {1, 2, 3, 4, 5};
    cout << solution.minimum(v);
}