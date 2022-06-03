#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<vector<int>> dp(n, vector(2, 0));
    dp[0][1] = 1;
    dp[0][0] = 0;
    long ans = 0;
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i-1]) {
            dp[i][0] = dp[i-1][1];
            dp[i][1] = dp[i-1][0] + i + 1;
        } else {
            dp[i][0] = dp[i-1][0];
            dp[i][1] = dp[i-1][1] + i + 1;
        }
    }

    cout << min(dp[n-1][0], dp[n-1][1]);

}


#include <bits/stdc++.h>

using namespace std;

//int main() {
//    string s;
//    cin >> s;
//    int n = s.size();
//    vector<int> dp(n, 0);
//    dp[0] = 0;
//    long ans = 0;
//    for (int i = 1; i < n; i++) {
//        if (s[i] == s[i-1]) {
//            s[i] = s[i] == 1 ? 0 : 1;
//            dp[i] = dp[i-1] + 1;
//            ans += i + 1;
//        }
//    }
//    cout << ans;
//
//}