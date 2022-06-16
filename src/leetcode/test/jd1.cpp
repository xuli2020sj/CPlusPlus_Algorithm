#include <bits/stdc++.h>

using namespace std;

void process() {
    int n;
    cin >> n;
    vector<string> v(n+1, "");
    for (int i = 0; i < n+1; i++) {
        getline(cin, v[i], '\n');
    }

    stack<int> st;

    for (int i = 1; i < n+1; i++) {
        if (v[i] == "while") {
            st.push(1);
        } else if (v[i] == "loop") {
            st.push(2);
        } else if (v[i] == "for") {
            st.push(3);
        } else if (v[i] == "switch") {
            st.push(4);
        } else if (v[i] == "if") {
            st.push(5);
        } else {
            int temp = 0;
            if (v[i] == "end while") {
                temp = -1;
            } else if (v[i] == "end loop") {
                temp = -2;
            } else if (v[i] == "end for") {
                temp = -3;
            } else if (v[i] == "end switch") {
                temp = -4;
            } else if (v[i] == "end if") {
                temp = -5;
            }

            if (st.empty() || temp * -1 != st.top()) {
                cout << "No" << endl;
                return;
            } else {
                st.pop();
            }
        }
        }

    if (st.empty()) {
        cout << "Yes" << endl;
    }
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        process();
    }
}
