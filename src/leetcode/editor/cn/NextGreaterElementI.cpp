//496下一个更大元素 I
//2022-06-14 10:38:13
/**
nums1 中数字 x 的 下一个更大元素 是指 x 在 nums2 中对应位置 右侧 的 第一个 比 x 大的元素。 

 给你两个 没有重复元素 的数组 nums1 和 nums2 ，下标从 0 开始计数，其中nums1 是 nums2 的子集。 

 对于每个 0 <= i < nums1.length ，找出满足 nums1[i] == nums2[j] 的下标 j ，并且在 nums2 确定 nums2
[j] 的 下一个更大元素 。如果不存在下一个更大元素，那么本次查询的答案是 -1 。 

 返回一个长度为 nums1.length 的数组 ans 作为答案，满足 ans[i] 是如上所述的 下一个更大元素 。

 示例 1： 

 
输入：nums1 = [4,1,2], nums2 = [1,3,4,2].
输出：[-1,3,-1]
解释：nums1 中每个值的下一个更大元素如下所述：
- 4 ，用加粗斜体标识，nums2 = [1,3,4,2]。不存在下一个更大元素，所以答案是 -1 。
- 1 ，用加粗斜体标识，nums2 = [1,3,4,2]。下一个更大元素是 3 。
- 2 ，用加粗斜体标识，nums2 = [1,3,4,2]。不存在下一个更大元素，所以答案是 -1 。 

 示例 2： 

 
输入：nums1 = [2,4], nums2 = [1,2,3,4].
输出：[3,-1]
解释：nums1 中每个值的下一个更大元素如下所述：
- 2 ，用加粗斜体标识，nums2 = [1,2,3,4]。下一个更大元素是 3 。
- 4 ，用加粗斜体标识，nums2 = [1,2,3,4]。不存在下一个更大元素，所以答案是 -1 。
 

 

 提示： 

 
 1 <= nums1.length <= nums2.length <= 1000 
 0 <= nums1[i], nums2[i] <= 10⁴ 
 nums1和nums2中所有整数 互不相同 
 nums1 中的所有整数同样出现在 nums2 中 
 

 

 进阶：你可以设计一个时间复杂度为 O(nums1.length + nums2.length) 的解决方案吗？ 
 Related Topics 栈 数组 哈希表 单调栈 👍 749 👎 0

*/

#include "bits/stdc++.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_map<int, int> map;
        for (int i = 0; i < nums2.size(); i++) {
            map[nums2[i]] = i;
        }
        for (auto num : nums1) {
            auto iter = map.find(num);
            if (iter->second == nums2.size()-1) {
                res.push_back(-1);
                continue ;
            }
            for (int i = iter->second + 1; i < nums2.size(); i++) {
                if (nums2[i] > num) {
                    res.push_back(nums2[i]);
                    break ;
                }
                if (i == nums2.size()-1) res.push_back(-1);
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<int> v1{4,1,2};
    vector<int> v2{1,3,4,2};
    s.nextGreaterElement(v1, v2);
}

