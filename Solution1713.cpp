//
// Created by luzh on 2021/7/26.
//

#include "Solution1713.h"

#include <unordered_map>

int Solution1713::minOperations(vector<int> &target, vector<int> &arr) {
    unordered_map<int, int> uM;
    int n = target.size();
    for (int i = 0; i < n; i++) {
        uM[target[i]] = i;
    }
    vector<int> temp = {};
    for (int i = 0; i < arr.size(); i++) {
        if (uM.count(arr[i])) {
            temp.push_back(uM[arr[i]]);
        }
    }
    vector<int> dp = {};
    for (int i = 0; i < temp.size(); i++) {
        int num = temp[i];
        auto it = lower_bound(dp.begin(), dp.end(), num);
        if (it == dp.end()) {
            dp.push_back(num);
        } else {
            *it = num;
        }
    }
    return n - dp.size();
}
