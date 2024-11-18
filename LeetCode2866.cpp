//
// Created by luzehui on 2023/12/22.
//

#include "LeetCode2866.h"
#include <stack>

long long LeetCode2866::maximumSumOfHeights(vector<int> &maxHeights) {
    int n = maxHeights.size();
    stack<int> prefixStk, suffixStk;
    vector<long long> prefix(n, 0), suffix(n, 0);
    long long res = 0;
    for (int i = 0; i < n; i++) {
        while (!prefixStk.empty() && maxHeights[prefixStk.top()] > maxHeights[i]) {
            prefixStk.pop();
        }
        if (prefixStk.empty()) {
            prefix[i] = (long long)maxHeights[i] * (i + 1);
        } else {
            int j = prefixStk.top();
            prefix[i] = (long long)maxHeights[i] * (i - j) + prefix[j];
        }
        prefixStk.push(i);
    }
    for (int i = n - 1; i >= 0; i--) {
        while (!suffixStk.empty() && maxHeights[suffixStk.top()] > maxHeights[i]) {
            suffixStk.pop();
        }
        if (suffixStk.empty()) {
            suffix[i] = (long long)maxHeights[i] * (n - i);
        } else {
            int j = suffixStk.top();
            suffix[i] = (long long)maxHeights[i] * (j - i) + suffix[j];
        }
        suffixStk.push(i);
        res = max(res, (long long)(suffix[i] + prefix[i] - maxHeights[i]));
    }
    return res;
}
