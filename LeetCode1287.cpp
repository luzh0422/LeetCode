//
// Created by luzehui on 25-2-17.
//

#include "LeetCode1287.h"

int LeetCode1287::findSpecialInteger(vector<int> &arr) {
    int n = arr.size();
    int target = (n + 3) / 4;
    int index1 = 0, index2 = 0;
    int res = -1, count = -1;
    while (index1 < n) {
        int num1 = arr[index1];
        while (index2 < n && arr[index2] == num1)
            index2++;
        if (index2 - index1 >= target && index2 - index1 > count) {
            res = num1;
        }
        index1 = index2;
    }
    return res;
}
