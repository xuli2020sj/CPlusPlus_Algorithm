//
// Created by x on 2022/6/22.
//

#include <bits/stdc++.h>
using namespace std;


int GetMinCoinCount(int total_amount, const vector<int>& values, int current) {

}

int main() {
    vector<int> values = {3, 5};
    sort(values.begin(), values.end(), greater<>());
    int total_amount = 11;
    int min_coins = GetMinCoinCount(total_amount, values, 0);
}