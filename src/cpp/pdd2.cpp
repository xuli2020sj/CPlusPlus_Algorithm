#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    int n , v;
    cin >> T;

    for (int t = 0; t < T; t++) {
        cin >> n >> v;
        vector<vector<int>> info(n, vector<int>(3, 0));
        int maxDay = 0;
        for (int i = 0; i < n; i++) {
            cin >> info[i][0] >> info[i][1] >> info[i][2];
            maxDay = max(maxDay, info[i][2]);
        }
        sort(info.begin(), info.end(), [](const vector<int>& v1, const vector<int>& v2) {
            if (v1[2] == v2[2]) {
                return v1[1] < v2[1];
            } else {
                return v1[2] < v2[2];
            }
        });

        long ans = 0;
        for (int day = 1; day <= maxDay; day++) {
            int cut = v;
            int j = 0;
            while (cut > 0 && j < n) {
                if (info[j][0] > 0 && day >= info[j][1] && day <= info[j][2]  ) {
                    if (info[j][0] >= cut) {
                        info[j][0] -= cut;
                        cut = 0;
                    } else {
                        cut -= info[j][0];
                        info[j][0] = 0;
                    }
                }
                ++j;
            }
            ans = ans + v - cut;

        }
        cout << ans;
    }
}