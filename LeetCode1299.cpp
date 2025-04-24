//
// Created by luzehui on 25-2-16.
//

#include "LeetCode1299.h"

vector<int> LeetCode1299::replaceElements(vector<int> &arr) {
    int n = arr.size() - 1;
    int currMaxNum = arr[n];
    arr[n] = -1;
    n--;
    while (n >= 0) {
        int temp = arr[n];
        arr[n] = currMaxNum;
        currMaxNum = max(temp, currMaxNum);
        n--;
    }
    return arr;
}
