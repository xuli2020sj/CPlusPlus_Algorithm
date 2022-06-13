#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        if (income <= 0) return 0;
        int n = brackets.size();
        double res = 0.;
        if (income < brackets[0][0]) {
            res += income * brackets[0][1] * 0.01;
            return res;
        } else {
            res += brackets[0][0] * brackets[0][1] * 0.01;
        }
        for (int i = 1; i < n; i++) {
            if (income > brackets[i-1][0] && income < brackets[i][0]) {
                res += (income-brackets[i-1][0]) * brackets[i][1] * 0.01;
                break ;
            } else if (income > brackets[i-1][0] && income >= brackets[i][0]) {
                res += (brackets[i][0] - brackets[i-1][0]) * brackets[i][1] * 0.01;
            }
        }
        return res;
    }
};


int main() {
    Solution s;
    vector<vector<int>> brackets = {{3, 50}, {7, 10}, {12, 25}};
    cout << s.calculateTax(brackets, 10);
}