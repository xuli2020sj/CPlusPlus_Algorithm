#include <regex>
#include <string>
#include <iostream>
#include <cassert>
#include <fstream>

using namespace std;

int main() {
    ifstream ifs;
    ifs.open("1219_0_665.5_det_pos.mac", ios::in);
    stringstream buffer;
    buffer << ifs.rdbuf();
    cout << buffer.str() ;
    ifs.close();
}
