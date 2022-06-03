#include <bits/stdc++.h>

using namespace std;

void process(vector<string>& matrix, int x1, int y1, int x2, int y2) {
    for (int i = x1; i <= x2; i++) {
        for (int j = y1; j <= y2; j++) {
            if (islower(matrix[i][j])) {
                matrix[i][j] = toupper(matrix[i][j]);
            } else {
                matrix[i][j] = tolower(matrix[i][j]);
            }
        }
    }
}

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<string> matrix(n);
    for (int i = 0; i < n; i++) {
        cin >> matrix[i];
    }
    vector<vector<int>> pro(q, vector<int>(4, 0));
    for (int i = 0; i < q; i++) {
        cin >> pro[i][0] >> pro[i][1] >> pro[i][2] >> pro[i][3];
    }

    unique(pro.begin(), pro.end());

    for (auto & i : pro) {
        process(matrix, i[0]-1, i[1]-1, i[2]-1, i[3]-1);
    }



    for (auto & i : matrix) {
        cout << i << endl;
    }

}