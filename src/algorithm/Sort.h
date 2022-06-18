//
// Created by x on 2022/1/9.
//

#ifndef CPLUSPLUS_ALGORITHM_SORT_H
#define CPLUSPLUS_ALGORITHM_SORT_H

#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

//template <typename T>
//class Sort {
//public:
//    static void bubbleSort(vector<T>& vec);
//};

namespace sort{
    template<typename T>
    bool validateSort(vector<T>& nums) {
        if (nums.size() <= 1) return true;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i-1]) return false;
        }
        return true;
    }

    template<typename T>
    void bubbleSort(vector<T> &vec) {
        size_t n = vec.size();
        for (int i = 0; i < n; i++) {
            bool flag = false;
            for (int j = 0; j < n-1-i; j++) {
                if (vec[j] > vec[j+1]) {
                    int temp = vec[j];
                    vec[j] = vec[j+1];
                    vec[j+1] = temp;
                }
                flag = true;
            }
            if (!flag) return ;
        }
    }

    template<typename T>
    void insertionSort(vector<T>& vec) {
        size_t n = vec.size();
        for (int i = 1; i < n; i++) {
            int insert_val = vec[i];
            int j = i-1;
            for (; j >=0; j--) {
                if (vec[j] > insert_val) {
                    vec[j+1] = vec[j];
                } else {
                    break ;
                }
            }
            vec[j+1] = insert_val;
        }
    }

    template<typename T>
    void selectonSort(vector<T>& vec) {
        size_t n = vec.size();
        for (int i = 0; i < n; i++) {
            int min_index = i;
            for (int j = i+1; j < n; j++) {
                if (vec[j] < vec[min_index]) {
                    min_index = j;
                }
            }
            swap(vec[min_index], vec[i]);
        }
    }


    void merge_sort(vector<int>& vec, int left, int right, vector<int>& temp) {
        if (left >= right) return;
        int pivot = (left + right) >> 1;
        merge_sort(vec, left, pivot, temp);
        merge_sort(vec, pivot + 1, right, temp);

        int i = left, j = pivot + 1, k = 0;
        while (i <= pivot && j <= right) {
            if (vec[i] <= vec[j]) {
                temp[k++] = vec[i++];
            } else {
                temp[k++] = vec[j++];
            }
        }
        while (i <= pivot) temp[k++] = vec[i++];
        while (j <= right) temp[k++] = vec[j++];
        for (int i1 = left, j1 = 0; i1<=right; i1++, j1++) vec[i1] = temp[j1];
    }

    void merge_sort(vector<int>& vec) {
        if (vec.size() <= 1) return ;
        vector<int> temp(vec.size());
        merge_sort(vec, 0, vec.size()-1, temp);
    }


    template<typename T>
    void quickSort(vector<T>& nums, int left, int right) {
        if (left >= right) return;

        int pivot = rand() % (right - left + 1) + left;
        swap(nums[right], nums[pivot]);
        int i = left - 1;
        for (int j = left; j < right; j++) {
            if (nums[j] <= nums[right]) {
                i++;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[i+1], nums[right]);

        quickSort(nums, left, i);
        quickSort(nums, i+2, right);
    }

    template<typename T>
    void quickSort(vector<T>& nums) {
        if (nums.size() <= 1) return ;
        quickSort(nums, 0, nums.size()-1);
    }


    void countingSort(vector<int>& nums) {
        if (nums.size() <= 1) return ;
        auto max_ele = *max_element(nums.begin(),nums.end());
        vector<int> count_num(max_ele+1);
        for (auto num : nums) {
            count_num[num]++;
        }

        for (int i = 1; i < count_num.size(); i++) {
            count_num[i] += count_num[i-1];
        }

        vector<int> res(nums.size());
        for (auto num : nums) {
            int pos = count_num[num];
            res[pos] = num;
            count_num[num]--;
        }
        nums = res;
    }
}




#endif//CPLUSPLUS_ALGORITHM_SORT_H



























