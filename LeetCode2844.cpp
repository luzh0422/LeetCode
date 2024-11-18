//
// Created by luzehui on 2024/7/28.
//

#include "LeetCode2844.h"
#include <unordered_set>

int LeetCode2844::minimumOperations(std::string num) {
    int n = num.size();
    int ans = n;
    unordered_set<string> uS = {"00", "25", "50", "75"};
    for (int j = 0; j < n; j++) {
        if (num[j] == '0') {
            ans = min(ans, n - 1);
        }
        for (int i = 0; i < j; i++) {
            string s = "";
            s += num[i];
            s += num[j];
            if (uS.count(s)) {
                ans = min(ans, n - i - 2);
            }
        }
    }
    return ans;
}
