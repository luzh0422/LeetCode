//
// Created by 陆泽辉 on 2022/6/17.
//

#include "LeetCode1089.h"

void LeetCode1089::duplicateZeros(vector<int> &arr) {
    vector<int> temp(arr.begin(), arr.end());
    int n = arr.size(), index1 = 0, index2 = 0;
    while (index2 < n) {
        if (temp[index1] == 0) {
            arr[index2++] = temp[index1];
            arr[index2++] = temp[index1++];
        } else {
            arr[index2++] = temp[index1++];
        }
    }
}
