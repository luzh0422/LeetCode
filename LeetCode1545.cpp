//
// Created by luzehui on 2024/5/19.
//

#include "LeetCode1545.h"

int LeetCode1545::getWinner(vector<int> &arr, int k) {
    if (k >= arr.size()) {
        return *max_element(arr.begin(), arr.end());
    }
    queue<int> q;
    for (int i = 1; i < arr.size(); i++) {
        q.push(arr[i]);
    }
    return getWinner(q, k, arr.front(), 0);
}

int LeetCode1545::getWinner(queue<int> &arr, int k, int curr, int currStep) {
    if (currStep == k) {
        return curr;
    }
    auto top = arr.front();
    arr.pop();
    if (curr >= top) {
        arr.push(top);
        return getWinner(arr, k, curr, currStep + 1);
    }
    arr.push(curr);
    return getWinner(arr, k, top, 1);
}
