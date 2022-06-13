//504
//七进制数
//base-7

//给定一个整数 num，将其转化为 7 进制，并以字符串形式输出。 
//
// 
//
// 示例 1: 
//
// 
//输入: num = 100
//输出: "202"
// 
//
// 示例 2: 
//
// 
//输入: num = -7
//输出: "-10"
// 
//
// 
//
// 提示： 
//
// 
// -10⁷ <= num <= 10⁷ 
// 
// Related Topics 数学 👍 179 👎 0


#include <bits/stdc++.h>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) return "0";
        bool flag = num < 0;
        string res;
        num = abs(num);
        while (num > 0) {
            res.push_back(num % 7 + '0');
            num /= 7;
        }
        if (flag) res.push_back('-');
        reverse(res.begin(), res.end());
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)




int main() {
    
}

