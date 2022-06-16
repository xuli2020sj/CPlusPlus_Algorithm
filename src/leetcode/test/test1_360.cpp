#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    if (n == 0) {
        cout << 0;
        return 0;
    }
    vector<vector<int>> info;

    int countSumNo = 0;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (b == 0) {
            countSumNo += a;
        } else {
            info.push_back({a, b});
        }
    }

    int m = info.size();
    if (m == 0) {
        cout << countSumNo;
        return 0;
    }

    vector<vector<int>> dp(m, vector<int>(2, 0));

    sort(info.begin(), info.end(), [](const vector<int>& v1, const vector<int>& v2) {
        return v1[0] > v2[0];
    });

    dp[0][0] = info[0][0] + countSumNo;
    dp[0][1] = countSumNo * 2;

    for (int i = 1; i < m; i++) {
        dp[i][0] = max(dp[i-1][0], dp[i-1][1]) + info[i][0];
        dp[i][1] = max(dp[i-1][0], dp[i-1][1]) * 2;
    }
    cout << max(dp[m-1][0], dp[m-1][1]);
}