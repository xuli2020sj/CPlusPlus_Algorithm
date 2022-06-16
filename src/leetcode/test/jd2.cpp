#include <bits/stdc++.h>

using namespace std;

void process() {
    int n;
    cin >> n;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    cout << v[(n+1)/2] << endl;
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        process();
    }
}
