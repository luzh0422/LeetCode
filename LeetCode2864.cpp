//
// Created by luzehui on 2024/3/13.
//

#include "LeetCode2864.h"

string LeetCode2864::maximumOddBinaryNumber(std::string s) {
    int oneCount = 0, n = s.size();
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            oneCount++;
        }
    }
    string res = "";
    for (int i = 0; i < oneCount - 1; i++) {
        res += '1';
    }
    for (int i = 0; i < n - oneCount; i++) {
        res += '0';
    }
    res += '1';
    return res;
}
