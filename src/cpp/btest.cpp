#include <bits/stdc++.h>

using namespace std;


vector<int> split(const string &str, const string &pattern)
{
    vector<int> res;
    if (str.empty())
        return res;
    string strs = str + pattern;

    size_t pos = strs.find(pattern);
    size_t size = strs.size();

    while (pos != string::npos) {
        string x = strs.substr(0, pos);
        res.push_back(stoi(x));
        strs = strs.substr(pos + 1, size);
        pos = strs.find(pattern);
    }
    return res;
}

//int search(vector<int>& nums, int target) {
//    int left = 0, right = nums.size() - 1;
//    while (left <= right) {
//        int mid = (left + right) / 2 ;
//        if (nums[mid] == target) return mid;
//        if (nums[0] <= nums[mid]) {
//            if (nums[mid] > target && nums[left] <= target) {
//                right = mid - 1;
//            } else {
//                left = mid + 1;
//            }
//        } else {
//            if (nums[right] >= target && nums[mid] < target) {
//                left = mid + 1;
//            } else {
//                right = mid - 1;
//            }
//        }
//    }
//    return INT_MIN;
//}
int search(vector<int>& nums, int target) {
    if(nums.size()==0) return -1;
    int l = 0, r = nums.size()-1, mid, mid2;
    while(l<r){
        while(nums[l]==nums[r] && r>l) r--;//首先去除最右边的重复元素
        mid = (l+r)/2;
        if(mid+1<=r){                      //将划分边界上重复的数字全部滑向右边
            int temp = nums[mid+1];
            for(int i=mid;i>=l;i--){
                if (nums[i]!=temp){
                    mid = i;
                    break;
                }
            }
        }
        if(nums[l]<=nums[mid]){ //左边有序，先看左边
            if(target>=nums[l] && target<=nums[mid]) r = mid;
            else l = mid+1;
        }
        else{                   //右边有序，先看右边
            if(target>=nums[mid+1] && target<=nums[r]) l = mid+1;
            else r = mid;
        }
    }
    if(nums[l] == target) return l;
    else return -1;
}

// [2,5,6,0,0,1,2], 0
int main() {
    string input;
    int target;
    cin >> input;
    cin >> target;
    int n = input.size();
    vector<int> nums;
    int end = input.find_first_of(']') - 1;
    auto x = split(input.substr(1, end), ",");


    if (search(nums, target) == -1) {
        cout << "false" << endl;
    } else {
        cout << "true" << endl;
    }

}




//int m = 0, n = 0;
//
//int dfs(vector<vector<int>>& info, int i, int j) {
//    if (i < 0 || i >= m || j < 0 || j >= n || info[i][j] == 1) return 0;
//    //    cout << t << endl;
//    info[i][j] = 1;
//    return dfs(info, i, j + 1) + dfs(info, i + 1, j) + dfs(info, i, j - 1) + dfs(info, i - 1, j) + 1;
//
//}

//    cin >> m >> n;
//    vector<vector<int>> info(m, vector<int>(n, 0));
//    for (int i = 0; i < m; i++) {
//        for (int j = 0; j < n; j++) {
//            cin >> info[i][j];
//        }
//    }
//
//    int ans = 0;
//
//    for (int i = 0; i < m; i++) {
//        for (int j = 0; j < n; j++) {
////            cout << i << j << endl;
//            if (info[i][j] == 0) ans = max(ans, dfs(info, i, j));
//        }
//    }
//    cout << ans << endl;
////    for (int i = 0; i < m; i++) {
////        for (int j = 0; j < n; j++) {
////            cout << info[i][j] << " ";
////        }
////        cout << endl;
////    }