//
//
//#include <bits/stdc++.h>
//
//using namespace std;
//
//int main() {
//    int n;
//    cin >> n;
//
//    vector<vector<int>> price(n, vector<int>(2, 0));
//    for (int i = 0; i < n; i++) {
//        cin >> price[i][0];
//    }
//
//    for (int i = 0; i < n; i++) {
//        cin >> price[i][1];
//    }
//
//    int fullDiscountNum = 0;
//    cin >> fullDiscountNum;
//    vector<vector<int>> fullDiscount(fullDiscountNum, vector<int>(2, 0));
//
//    for (int i = 0; i < fullDiscountNum; i++) {
//        cin >> fullDiscount[i][0];
//    }
//
//    for (int i = 0; i < fullDiscountNum; i++) {
//        cin >> fullDiscount[i][1];
//    }
//
//
//    int sumDiscount = 0;
//    int sumPrice = 0;
//    for (int i = 0; i < n; i++) {
//        int currPrice = price[i][0];
//        int currDiscount = price[i][1];
//        sumPrice += currPrice;
//        sumDiscount += currDiscount;
//
//        int fullDiscountPrice = 0;
//        int minFullDiscountPrice = sumPrice;
//        for (int j = 0; j < fullDiscountNum && fullDiscount[j][0] <= sumPrice; j++) {
//            if (sumPrice >= fullDiscount[j][0]) {
//                fullDiscountPrice = sumPrice - fullDiscount[j][1];
//                if (fullDiscountPrice < minFullDiscountPrice) {
//                    minFullDiscountPrice = fullDiscountPrice;
//                }
//            }
//        }
//
//        if (minFullDiscountPrice > sumDiscount) {
//            cout << 'Z';
//        } else if (minFullDiscountPrice < sumDiscount) {
//            cout << 'M';
//        } else {
//            cout << 'B';
//        }
//    }
//}