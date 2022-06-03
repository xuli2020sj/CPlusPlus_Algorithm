#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    string s;
    cin >> n >> k;
    cin >> s;
    unordered_map<char, int> map;
    int left = 0;
    int right = 0;
    int currKind = 0;
    int ans = 0;
    while (right < n) {
        char c1 = s[right];
        right++;
        if (!map.count(c1) || map[c1] == 0) currKind++;
        map[c1]++;
        while (currKind > k) {
            char c2 = s[left];
            map[c2]--;
            if (map[c2] == 0) currKind--;
            left++;
        }
        ans = max(ans, right - left);
    }
    cout << ans;
}