//
// Created by luzehui on 2023/10/29.
//

#include "LeetCode275.h"

int LeetCode275::hIndex(vector<int> &citations) {
//    int left = citations.front(), right = citations.back();
//    int size = citations.size();
//    for (int i = left; i <= right; i++) {
//        int index = binarySearch(citations, i);
//        if (size - index == i) {
//            return i;
//        }
//    }
//    return -1;
    int n = citations.size();
    int left = 0, right = citations.size() - 1;
    while (left <= right) {
        int middle = (left + right) / 2;
        if (citations[middle] >= (n - middle)) {
            right = middle - 1;
        } else {
            left = middle + 1;
        }
    }
    return n - left;
}

int LeetCode275::binarySearch(vector<int> &citations, int target) {
    int left = 0, right = citations.size() - 1;
    int middle = (left + right) / 2;
    while (left < right) {
        if (citations[middle] < target) {
            left = middle + 1;
        } else {
            right = middle;
        }
        middle = (left + right) / 2;
    }
    return right;
}
