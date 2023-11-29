//
// Created by 陆泽辉 on 2023/5/11.
//

#include "LeetCode1016.h"
#include <unordered_set>

/**
 * 统计字符串s的所有子字符串的数字，并记录下来，判断数字的数量和n是否相等；
 * 如果相等，则能代表1 - n所有的数字，如果不相等，则无法代表1 - n所有的数字；
 * @param s
 * @param n
 * @return
 */
bool LeetCode1016::queryString(string s, int n) {
    unordered_set<int> cache{};
    int m = s.size();
    for (int i = 0; i < m; i++) {
        int curr = s[i] - '0';
        if (curr == 0) {
            continue;
        }
        for (int j = i + 1; curr <= n; j++) {
            cache.insert(curr);
            if (j == m) break;
            curr = (curr << 1) | (s[j] - '0'); // 子串 [i,j] 的二进制数
        }
    }
    return cache.size() == n;
}
