//
// Created by luzehui on 2024/4/18.
//

#include "LeetCode2007.h"

vector<int> LeetCode2007::findOriginalArray(vector<int> &changed) {
    int n = changed.size();
    if (n % 2 == 1) {
        return {};
    }
    std::sort(changed.begin(), changed.end());
    int left = 0, right = 1, count = 0;
    vector<int> res{};
    vector<int> visist(n, 0);
    while (right < n) {
        while (right < n && changed[left] * 2 != changed[right]) {
            right++;
        }
        if (right == n) {
            break;
        }
        res.push_back(changed[left]);
        visist[left] = 1;
        visist[right] = 1;
        count += 2;
        while (left < n && visist[left] == 1) {
            left++;
        }
        if (right <= left) {
            right = left + 1;
        } else {
            right++;
        }
    }
    if (count == n) {
        return res;
    }
    return {};
}
