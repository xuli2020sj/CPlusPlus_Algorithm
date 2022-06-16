#include <bits/stdc++.h>
using namespace std;

unsigned long long reverse(unsigned long long num) {
    string temp = to_string(num);
    reverse(temp.begin(), temp.end());
    for (int i = 0; i < temp.size(); i++) {
        if (temp[i] == '0') {
            continue;
        } else {
            return stol(temp.substr(i));
        }
    }
    return 0;
}

int main(){
    int N , K;
    cin >> N >> K;
    vector<unsigned long long> v(K, 0);
    unsigned long long ans = 0;
    for (int i = 1; i <= K; i++) {
        v[i] = i * N;
        ans = max(ans, reverse(v[i]));
    }
    cout << ans;
    return 0;
}