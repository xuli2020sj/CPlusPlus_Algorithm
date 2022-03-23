#include <bits/stdc++.h>

using namespace std;

int main() {
    int k;
    cin >> k;
    string b;
    cin >> b;
    int n = b.size();
    vector<int> B(n, 2);
    vector<int> A(n, 0);
    for (int i = 0; i < n; i++) {
        if (b[i] == '0') {
            B[i] = 0;
        } else {
            B[i] = 1;
        }
    }
    
    vector<int> used(n, 0);
    for (int i = 0; i < n; i++) {
        if (B[i] == 0) {
            if (i >= k) {
                A[i-k] = 0;
                used[i-k] = 1;
            }
            if (i + k < n) {
                A[i+k] = 0;
                used[i-k] = 1;
            }
        } else {
            if (i + k < n) {
                A[i+k] = 1;
            } else {
                A[i-k] = 1;
            }
        }
    }
    string ans;
    for (int i = 0; i < n; i++) {
        ans += std::to_string(A[i]);
    }
    cout << ans;

}

#include <bits/stdc++.h>

using namespace std;

int main() {
    int k;
    cin >> k;
    string b;
    cin >> b;
    int n = b.size();
    vector<int> B(n, 2);
    vector<int> A(n, 0);
    for (int i = 0; i < n; i++) {
        if (b[i] == '0') {
            B[i] = 0;
        } else {
            B[i] = 1;
        }
    }

    for (int i = 0; i < n; i++) {
        if (B[i] == 0) {
            if (i >= k) A[i-k] = 0;
            if (i + k < n) A[i+k] = 0;
        } else {
            if (i + k < n) {
                A[i+k] = 1;
            } else {
                A[i-k] = 1;
            }
        }
    }
    string ans;
    for (int i = 0; i < n; i++) {
        ans += std::to_string(A[i]);
    }
    cout << ans;

}