#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> h(N);
    for (int i = 0; i < N; i++) {
        cin >> h[i];
    }

    int need = 0;
    int currEnergy = 0;
    for (int i = 1; i < N; i++) {
        int dis = h[i-1] - h[i];
        currEnergy += dis;
        if (currEnergy < 0) {
            need = need - currEnergy;
            currEnergy = 0;
        }
    }
    cout << need;
}