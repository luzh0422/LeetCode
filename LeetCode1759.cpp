//
// Created by 陆泽辉 on 2022/12/26.
//

#include "LeetCode1759.h"

int LeetCode1759::countHomogenous(string s) {
    const int MOD = 1e9 + 7;
    long i = 0, j = 0, ans = 0;
    while (i < s.size()) {
        char curr = s[i];
        while (j < s.size() && s[j] == curr) {
            j++;
        }
        ans += (j - i) * (j - i + 1) / 2;
        ans %= MOD;
        i = j;
    }
    return ans;
}
