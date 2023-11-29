//
// Created by 陆泽辉 on 2022/6/27.
//

#include "LeetCode522.h"

/**
 * 策略问题，如果一个子串是特殊子串，则字符串中包含这个字符串的一定也是特殊子串，则题目转换到查找不是任何字符串子串的字符串；判断一个字符串是否是另一个字符串的子串，可以使用双指针的方法
 * @param strs
 * @return
 */
int LeetCode522::findLUSlength(vector<string> &strs) {
    /**
     * 判断s1是否是s2的子串；
     */
    auto isUniqueString = [](string& s1, string& s2) -> bool {
        int index1 = 0, index2 = 0, n1 = s1.size(), n2 = s2.size();
        while (index1 < n1 && index2 < n2) {
            if (s1[index1] == s2[index2]) {
                index1++;
                index2++;
            } else {
                index2++;
            }
        }
        if (index1 == n1) {
            return false;
        } else {
            return true;
        }
    };
    int n = strs.size();
    int ret = -1;
    for (int i = 0; i < n; i++) {
        bool check = true;
        for (int j = 0; j < n; j++) {
            if (i != j && !isUniqueString(strs[i], strs[j])) {
                check = false;
                break;
            }
        }
        if (check) {
            ret = max(ret, static_cast<int>(strs[i].size()));
        }
    }
    return ret;
}
