//
// Created by 陆泽辉 on 2023/4/3.
//

#include "LeetCode1053.h"

vector<int> LeetCode1053::prevPermOpt1(vector<int> &arr) {
    int n = arr.size();
    int i = n - 2;
    for (; i >= 0; i--) {
        if (arr[i] > arr[i + 1]) {
            break;
        }
    }
    int index = -1, temp = 0;
    for (int j = n - 1; j > i; j--) {
        if (arr[j] < arr[i] && arr[j] >= temp) {
            index = j;
            temp = arr[j];
        }
    }
    arr[index] = arr[i];
    arr[i] = temp;
    return arr;
}
