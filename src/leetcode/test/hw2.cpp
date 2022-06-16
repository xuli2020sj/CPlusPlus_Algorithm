#include <bits/stdc++.h>

using namespace std;

//void canFinish(int n, )

int main() {
    int N, M;
    cin >> N >> M;
    list<list<int>> list(M+1);
    auto iter = list.begin();
    for (int i = 0; i < M+1; i++) {
        string temp;
        cin >> temp;
        int start = -1;
        for (int j = 0; j < temp.size(); j++) {
            if (temp[j] == ',' || j == temp.size()-1) {
                int num = stoi(temp.substr(start, j-start));
                iter->push_back(num);
                start = j+1;
            }
        }
        iter++;
    }


}
