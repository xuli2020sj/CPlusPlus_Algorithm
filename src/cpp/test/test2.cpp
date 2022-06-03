
#include <bits/stdc++.h>
using namespace std;
void encode(string& s, int n, string& ans) {
    while (n) {
        int temp = (n + 1) / 2 - 1;
        --n;
        ans.push_back(s[temp]);
        s.erase(temp, 1);
    }
}

void decode(string& s, int n, string& ans) {
    int flag = 1;
    while (n >= 0) {
        char c = s[n-1];
        s.pop_back();
        if (flag > 0) {
            ans.push_back(c);
        } else {
            ans = c + ans;
        }
        flag *= -1;
        --n;
    }
}

int main() {
    int n , t;
    string s;
    cin >> n >> t;
    cin >> s;
    string ans;
    if (t == 1) {
        encode(s, n, ans);
    } else if (t == 2) {
        decode(s, n, ans);
    }
    cout << ans;
}