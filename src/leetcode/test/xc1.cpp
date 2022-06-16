#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    size_t n = s.size();
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= 9; j++) {
            if (i == 0 && j == 0) continue;
            string s_temp = s;
            string ins = to_string(j);
            s_temp.insert(i, ins.c_str());
            unsigned long temp = stoull(s_temp);
            if (temp % 7 == 0) {
                cout << temp;
                return 0;
            }
        }
    }

}