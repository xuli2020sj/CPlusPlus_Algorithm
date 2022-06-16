#include <bits/stdc++.h>
using namespace std;

int N;
int Q;

int process(string& s) {
    vector<int> dp(N, 0);
    dp[0] = 0;
    for (int i = 1; )
}


int main(){
    cin >> N >> Q;
    vector<string> v(Q);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    for (int i = 0; i < Q; i++) {
        cout << process(v[i]) << endl;
    }

}