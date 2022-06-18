//
// Created by x on 2022/1/9.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include "Search.h"

using namespace std;
/**
*
* @param vec
* @param left
* @param right
* @description left>=right 避免死循环
*/
void quick_sort(vector<int>& vec, int left, int right) {
    if (left >= right) return;
    int i = left - 1, j = right + 1, axis = (i + j) >> 1;
    while (i < j) {
        do i++; while (vec[i] < vec[axis]);
        do j--; while (vec[j] > vec[axis]);
        if (i < j) std::swap(vec[i], vec[j]);
    }
    quick_sort(vec, left, j);
    quick_sort(vec,  j + 1, right);
}

void quickSort(vector<int>& vec, int left, int right) {
    if (left >= right) return ;
    int i = left;
    int pivot = rand() % (right - left + 1) + left;
    swap(vec[pivot], vec[right]);
    for (int j = left; j < right; j++) {
        if (vec[j] < vec[right]) {
            swap(vec[i], vec[j]);
            i++;
        }
    }
    swap(vec[i], vec[right]);
    quickSort(vec, left, i);
    quickSort(vec, i+2, right);
}

void quick_sort(vector<int>& vec) {
    quick_sort(vec, 0, static_cast<int>(vec.size())-1);
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

void merge_sort(vector<int>& vec) {
    temp.resize(vec.size()); // 避免越界
    merge_sort(vec, 0, vec.size()-1);
}

/**
 *
 * @param vec
 * @param target
 * @return index
 */
int binary_search(vector<int>& vec, int target) {
    int left = 0, right = vec.size() - 1, mid = (left + right)  / 2;
    while (left <= right) {
        mid = (left + right) / 2;
        if (vec[mid] > target) {
            right = mid - 1;
        } else if (vec[mid] < target) {
            left = mid + 1;
        } else {
            return mid;
        }
    }
    return -1;
}

int binary_search_iterative(vector<int>& vec, int target, int left, int right) {
    if (left > right) return -1;
    int mid = (right - left) / 2;
    if (target == vec[mid]) {
        return mid;
    } else if (target > vec[mid]) {
        return binary_search_iterative(vec, target, mid+1, right);
    } else if (target < vec[mid]) {
        return binary_search_iterative(vec, target, left, mid-1);
    }
}

/**
 * 查找小于等于target的第一个元素
 * @param vec
 * @param target
 * @return
 */
int binary_search_lower_bound(vector<int>& vec, int target) {
    int left = 0, right = vec.size() - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (vec[mid] > target) {
            right = mid - 1;
        } else if (vec[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left < vec.size() ? left : -1;
}

/**
 * 查找大于等于给定值的以一个元素
 * @param vec
 * @param target
 * @return
 */
int binary_search_upper_bound(vector<int>& vec, int target) {
    int left = 0, right = vec.size() - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (vec[mid] > target) {
            right = mid - 1;
        } else if (vec[mid] < target) {
            left = mid + 1;
        } else {
            left = mid + 1;
        }
    }
    return right >= 0 ? right : -1;
}



int main() {
    vector<int> v {1, 4, 2, 3, 3, 9, 3,  5, 9, 9};
    // stl method
    vector<int> v1 = v;
    std::sort(v1.begin(), v1.end());
    std::for_each(v1.begin(), v1.end(), [](int x){
        cout << x << " ";
    });
    cout << endl;
    cout << "lower bound pos: " << lower_bound(v1.begin(), v1.end(), 7) - v1.begin() << endl;
    cout << "upper bound pos: " << upper_bound(v1.begin(), v1.end(), 7) - v1.begin() << endl;

    cout << endl;

    // my method
    cout << "quick sort" << endl;
    vector<int> v2 = v;
//    quick_sort(v2);
    quickSort(v2, 0, v2.size()-1);
    std::for_each(v2.begin(), v2.end(), [](int x){
        cout << x << " ";
    });
    cout << endl;
    cout << "binary search index : " << binary_search(v2, 9) << endl;
    cout << "binary search index lower_bound: " << binary_search_lower_bound(v2, 7) << endl;
    cout << "binary search index upper_bound: " << binary_search_upper_bound(v2, 7) << endl;
    cout << endl;

//    cout << "merge sort" << endl;
//    vector<int> v3 = v;
//    merge_sort(v3);
//    std::for_each(v3.begin(), v3.end(), [](int x){
//        cout << x << " ";
//    });
//    cout << endl;
    return 0;
}

