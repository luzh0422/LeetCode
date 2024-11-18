//
// Created by luzehui on 2024/9/27.
//

#include "LeetCode2516.h"

int LeetCode2516::takeCharacters(std::string s, int k) {
    int n = s.size();
    vector<int> aPreSum(n + 1, 0), bPreSum(n + 1, 0), cPreSum(n + 1, 0);
    for (int i = 0; i < n; i++) {
        aPreSum[i + 1] = aPreSum[i];
        bPreSum[i + 1] = bPreSum[i];
        cPreSum[i + 1] = cPreSum[i];
        if (s[i] == 'a') {
            aPreSum[i + 1]++;
        } else if (s[i] == 'b') {
            bPreSum[i + 1]++;
        } else {
            cPreSum[i + 1]++;
        }
    }
    if (aPreSum.back() < k || bPreSum.back() < k || cPreSum.back() < k) {
        return -1;
    }
    int left = 0, right = n, res = INT_MAX;
    while (right >= left && (aPreSum[n] - aPreSum[right] + aPreSum[left] < k || bPreSum[n] - bPreSum[right] + bPreSum[left] < k || cPreSum[n] - cPreSum[right] + cPreSum[left] < k)) {
        right--;
    }
    res = min(res, left + n - right);
    left++;
    while (left < n + 1) {
        while (right < n + 1 && (aPreSum[n] - aPreSum[right] + aPreSum[left] >= k && bPreSum[n] - bPreSum[right] + bPreSum[left] >= k && cPreSum[n] - cPreSum[right] + cPreSum[left] >= k)) {
            right++;
        }
        res = min(res, left + n - right + 1);
        left++;
    }
    return res;
}
