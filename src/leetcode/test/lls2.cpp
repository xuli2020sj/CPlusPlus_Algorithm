#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param array int整型vector
     * @param k int整型
     * @return long长整型
     */
    long long ans(vector<int>& array, int k) {
        // write code here
        long long res = 0;
        sort(array.begin(), array.end());
        long right = array.size()-1;
        long left = 0;
        while (right > left) {
            long long temp = array[right] + array[left];
            if (temp > k) {
                upper_bound(array.begin()+left-1)
                do right--; while (right > left && array[right] + array[left] > k);
            } else if (temp <= k) {
                res++;
                left++;
                bool flag = false;
                while (right > left && array[left] == array[left-1]) {
                    flag = true;
                }
                if (flag) res++;
                res = res + (right - left);

            }
        }
        return res;
    }
};

int main(){
    Solution solution;
    vector<int> v = {3, 1, 2};
    cout << solution.ans(v, 5);

}