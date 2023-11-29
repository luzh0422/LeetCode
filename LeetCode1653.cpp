//
// Created by 陆泽辉 on 2023/3/6.
//

#include "LeetCode1653.h"
#include <vector>

int LeetCode1653::minimumDeletions(string s) {
    int n = s.size();
    vector<int> bPrefix(n, 0);
    vector<int> aSuffix(n + 1, 0);
    int bCount = 0, aCount = 0;
    for (int i = 0; i < n; i++) {
        bPrefix[i] = bCount;
        if (s[i] == 'b') {
            bCount++;
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        aSuffix[i] = aCount;
        if (s[i] == 'a') {
            aCount++;
        }
    }
    int res = INT_MAX;
    for (int i = 0; i < n; i++) {
        res = min(res, bPrefix[i] + aSuffix[i]);
    }
    return res;

}
