//
// Created by 陆泽辉 on 2022/8/25.
//

#include "LeetCode658.h"

vector<int> LeetCode658::findClosestElements(vector<int> &arr, int k, int x) {
    int index = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
    int left = index - 1, right = index;
    int n = arr.size();
    vector<int> ret = {};
    int count = 0;
    while (count < k && left >= 0 && right < n) {
        if (abs(arr[left] - x) <= abs(arr[right] - x)) {
            ret.insert(ret.begin(), arr[left]);
            left--;
        } else {
            ret.push_back(arr[right]);
            right++;
        }
        count++;
    }
    while (count < k && left >= 0) {
        ret.insert(ret.begin(), arr[left]);
        left--;
        count++;
    }
    while (count < k && right < n) {
        ret.push_back(arr[right]);
        right++;
        count++;
    }
    return ret;
}
