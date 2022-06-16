//
// Created by x on 2022/1/9.
//

#ifndef CPLUSPLUS_ALGORITHM_SORT_H
#define CPLUSPLUS_ALGORITHM_SORT_H

#include <cstdlib>
#include <vector>
using namespace std;

//template <typename T>
//class Sort {
//public:
//    static void bubbleSort(vector<T>& vec);
//};

namespace sort{
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

    vector<int> temp;
    void merge_sort(vector<int>& vec, int left, int right) {
        if (left >= right) return;
        int axis = (left + right) >> 1;
        merge_sort(vec, left, axis);
        merge_sort(vec, axis + 1, right);

        int i = left, j = axis + 1, k = 0;
        while (i <= axis && j <= right) {
            if (vec[i] <= vec[j]) {
                temp[k++] = vec[i++];
            } else {
                temp[k++] = vec[j++];
            }
        }
        while (i <= axis) temp[k++] = vec[i++];
        while (j <= right) temp[k++] = vec[j++];
        for (int i1 = left, j1 = 0; i1<=right; i1++, j1++) vec[i1] = temp[j1];
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
}




#endif//CPLUSPLUS_ALGORITHM_SORT_H
