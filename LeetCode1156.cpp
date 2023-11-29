//
// Created by 陆泽辉 on 2023/6/3.
//

#include "LeetCode1156.h"

#include <unordered_map>

int LeetCode1156::maxRepOpt1(string text) {
    unordered_map<char, int> count;
    int n = text.size();
    for (int i = 0; i < n; i++) {
        count[text[i]]++;
    }
    int i = 0, j = 0, k;
    int res = 0;
    while (i < n) {
        // 搜索当前字符text[i]的重复子串
        while (j < n && text[j] == text[i]) {
            j++;
        }
        if (count[text[i]] == j - i) {
            res = max(res, j - i); // 没有可以交换的字符，直接更新res；
        } else {
            res = max(res, j - i + 1); // 交换一个字符，原长度 + 1；
            k = j + 1; // 从j之后搜索间隔一个字符的相同字符重复子串；
            while (j < n && text[i] == text[k]) {
                k++;
            }
            res = max(res, min(k - i, count[text[i]]));
        }
    }
    return res;
}
