#include <string>
#include <iostream>

using namespace std;

void trim(string& s) {
    if (s.empty()) return;
    s.erase(0, s.find_first_not_of(' '));
    s.erase(s.find_last_not_of(' ')+1);
}


int main() {
    string s;
    string s1[9];
//    cin >> s;
    getline(cin, s);

    cout << s << endl;
    cout << s.size() << endl;
    trim(s);
    cout << s << endl;
    cout << s.size() << endl;
}

