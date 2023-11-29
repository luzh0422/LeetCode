//
// Created by 陆泽辉 on 2023/6/27.
//

#include "LeetCode1186.h"

int LeetCode1186::maximumSum(vector<int> &arr) {
    int n = arr.size();
    int res = INT_MIN, temp = 0;
    // 不删除某个元素的最大值；
    for (int i = 0; i < n; i++) {
        if (temp > 0) {
            res = max(temp + arr[i], res);
            temp += arr[i];
        } else {
            res = max(arr[i], res);
            temp = arr[i];
        }
    }
    // 删除某个元素的最大值；
    vector<int> l(n, 0), r(n, 0);
    l[0] = arr[0];
    for (int i = 1; i < n; i++) {
        l[i] = l[i - 1] > 0 ? l[i - 1] + arr[i] : arr[i];
    }
    r[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        r[i] = r[i + 1] > 0 ? r[i + 1] + arr[i] : arr[i];
    }
    for (int i = 1; i < n - 1; i++) {
        res = max(res, l[i - 1] + r[i + 1]);
    }
    res = max({res, l[n - 1], r[0]});
    return res;
}
