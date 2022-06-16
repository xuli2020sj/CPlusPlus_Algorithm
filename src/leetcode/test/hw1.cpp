/*
 *
 *
 *
 *
 */
#include <bits/stdc++.h>

using namespace std;


int main() {
    int topN, M;
    cin >> topN >> M;



    vector<string> v(2 * M);
    int count = 0;
    while (true) {
        string temp;
        if (cin.get() == '\n') {
            count++;
            if (count == 2 * M) break;

        }
        cin >> temp;
        v.push_back(temp);
    }
//    for (int i = 0; i < 2 * M; i++) {
//        while (cin. == '\n') {
//            string temp;
//            cin >> temp;
//            v[i] += temp;
//            v[i] += ' ';
//        }
//    }

    map<string, int> map;
    for (auto s : v) {
        for (int i = 0; i < s.size(); i++) {
            int start = 0;
            if (s[i] == ' ') {
                string temp = s.substr(start, i - start);
                map[temp] += 1;
                start = i + 1;
            }
        }
    }
    auto iter = map.begin();

    for (int i = 0; i < topN; i++) {
        cout << iter->first << ' ';
        iter++;
    }

}
