//
// Created by luzh on 2021/6/15.
//

#include "Solution852.h"

int Solution852::peakIndexInMountainArray(vector<int> &arr) {
    int start = 1, end = arr.size() - 2;
    while (start <= end) {
        if (arr[start] > arr[start - 1] && arr[start] > arr[start + 1]) {
            return start;
        }
        if (arr[end] > arr[end - 1] && arr[end] > arr[end + 1]) {
            return end;
        }
        start++;
        end--;
    }
    return -1;
}
