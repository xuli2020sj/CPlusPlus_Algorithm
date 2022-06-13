//
// Created by x on 2022/6/11.
//

#include "bits/stdc++.h"
using namespace std;

typedef union data {
    float f_data;
    char c_data[4];
};


int main() {
    data d{};
    cout << sizeof(d) << endl;
    string s = "01000001001100110011001100110011";
    d.c_data[3] = stoi(s.substr(0, 8), nullptr, 2);
    d.c_data[2] = stoi(s.substr(8, 8), nullptr, 2);
    d.c_data[1] = stoi(s.substr(16, 8), nullptr, 2);
    d.c_data[0] = stoi(s.substr(24, 8), nullptr, 2);
    cout << d.c_data[1] << endl;
    cout << s.substr(0, 8) << endl;
    cout << s.substr(8, 8) << endl;
    cout << s.substr(16, 8) << endl;
    cout << s.substr(24, 8) << endl;

    cout << d.f_data << endl;
}