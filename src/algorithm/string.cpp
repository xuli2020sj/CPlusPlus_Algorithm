//
// Created by x on 2022/2/18.
//

#include <iostream>
#include <string>

using namespace std;


int main() {
    string s = "abcde";
    string s1 = "fgh";
    cout << s << endl;

    // delete
    s.erase(1, 2);
    cout << s << endl;

    //insert
    s.push_back(s1[1]);
    //s.insert(1, reinterpret_cast<const char *>(s[0]));


    cout << typeid(s[1]).name() << endl;

    s1 = s + s1;
    cout << "a" << s1[9] << "a" << endl;
}