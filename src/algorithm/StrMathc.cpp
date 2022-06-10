//
// Created by x on 2022/6/6.
//

#include "bits/stdc++.h"

using namespace std;

bool bf(string str, string match) {
    size_t s_len = str.size();
    size_t m_len = match.size();
    if (m_len == 0 || m_len > s_len) return false;
    for (int i = 0; i < s_len; i++) {
        int curr_i = i;
        for (int j = 0; j < m_len; j++) {
            if (str[curr_i] == match[j]) {
                curr_i++;
            } else {
                break ;
            }
            if (j == m_len-1) return true;
        }
    }
    return false;
}

int main() {
    string s = "badef";
    string m1 = "adeft";
    cout << bf(s, m1) << endl;
}