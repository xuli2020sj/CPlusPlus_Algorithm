#include <bits/stdc++.h>
using namespace std;

bool valid(int n1, int n2) {
    int temp = n1 < n2 ? n1 : n2;
    while (temp > 1) {
        if (n1 % temp == 0 && n2 % temp == 0) {
            return false;
        }
        temp--;
    }
    return true;
}

bool valid2(int n1, int n2) {
    int t1 = n1 > n2 ? n1 : n2;
    int t2 = n1 < n2 ? n1 : n2;
    int temp = t1 - t2;
    while (temp != 1 && temp != t2) {
        if (t2 > temp) {
            t1 = t2;
            t2 = temp;
        } else {
            t1 = temp;
        }
        temp = t1 - t2;
    }
    return temp == 1;
}


void gcd(int n, vector<pair<int, int>>& vGCD) {
    int left = 1, right = n;
    while (left < right) {
        int temp = left * right;
        if (temp > n) {
//            right--;
            do right--; while (left * right > n);
        } else if (temp < n) {
//            left++;
            do left++; while (left * right < n);
        } else {
            if (valid2(left, right)) vGCD.emplace_back(left, right);
            left++;
            right--;
        }
    }
}

int main(){
    int t;
    cin >> t;

    vector<int> v(t, 0);
    for (int i = 0; i < t; i++) {
        cin >> v[i];
    }

    vector<pair<int, int>> vGCD;
    for (int i = 0; i < t; i++) {
        vGCD.clear();
        gcd(v[i], vGCD);
        cout << vGCD.size() << endl;
    }

}