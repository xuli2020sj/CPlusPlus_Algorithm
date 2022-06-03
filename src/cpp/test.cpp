#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size();
        vector<int> dis(n, 0);
        for (int i = 0; i < n; i++) {
            dis[i] = capacity[i] - rocks[i];
        }
        sort(dis.begin(), dis.end());
        int res = 0;
        for (int i = 0; i < n && additionalRocks > 0; i++) {
            if (additionalRocks >= dis[i]) {
                additionalRocks -= dis[i];
                res++;
            } else {
                break;
            }
        }
        return res;
    }
};


int main() {
    Solution s;
    cout << s.percentageLetter("jjj", 'k');
 }
