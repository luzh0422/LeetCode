//
// Created by luzehui on 2024/10/30.
//

#include "LeetCode3216.h"

string LeetCode3216::getSmallestString(std::string s) {
    int num1 = s[0] - '0', n = s.size();
    for (int i = 1; i < n; i++) {
        int num2 = s[i] - '0';
        if (((num1 & 1) ^ (num2 & 1)) != 0 && num1 > num2) {
            char c = s[i - 1];
            s[i - 1] = s[i];
            s[i] = c;
            break;
        }
        num1 = num2;
    }
    return s;
}
