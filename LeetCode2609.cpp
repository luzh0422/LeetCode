//
// Created by luzehui on 2023/11/8.
//

#include "LeetCode2609.h"

int LeetCode2609::findTheLongestBalancedSubstring(std::string s) {
    int n = s.size() - 1;
    int countOne = 0, countZero = 0;
    int ans = 0;
    for (int i = n; i >= 0; i--) {
        int j = i;
        for (; j >= 0; j--) {
            if (s[j] == '1') {
                if (countZero != 0) {
                    break;
                }
                countOne++;
            } else if (s[j] == '0') {
                if (countOne == 0) {
                    break;
                }
                countZero++;
            }
        }
        ans = max(ans, min(countZero, countOne) * 2);
        countOne = 0, countZero = 0;
    }
    return ans;
}
