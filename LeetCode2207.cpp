//
// Created by luzehui on 2024/9/24.
//

#include "LeetCode2207.h"

long long LeetCode2207::maximumSubsequenceCount(std::string text, std::string pattern) {
//    char c1 = pattern[0], c2 = pattern[1];
//    int num1 = 0, num2 = 0, n = text.size();
//    if (c1 == c2) {
//        int count = 0;
//        for (int i = 0; i < n; i++) {
//            if (text[i] == c1) {
//                count++;
//            }
//        }
//        return count * (count + 1) / 2;
//    }
//    long long c1Res = 0ll, c1Num = 0ll, c2Res = 0ll, c2Num = 0ll;
//    for (int i = 0; i < n; i++) {
//        if (c1 == text[i]) {
//            num1++;
//            c1Res = max(c1Res, (long long)num1);
//            c1Res = max(c1Res, c1Num + num1);
//        } else if (c2 == text[i]) {
//            c1Num += num1;
//            c1Res = max(c1Res, c1Num);
//            c1Res = max(c1Res, c1Num + num1);
//        } else {
//            c1Res = max(c1Res, c1Num + num1);
//        }
//    }
//    for (int i = n - 1; i >= 0; i--) {
//        if (c1 == text[i]) {
//            c2Num += num2;
//            c2Res = max(c2Res, c2Num);
//            c2Res = max(c2Res, c2Num + num2);
//        } else if (c2 == text[i]) {
//            num2++;
//            c2Res = max(c2Res, (long long)num2);
//            c2Res = max(c2Res, c2Num + num2);
//        } else {
//            c2Res = max(c2Res, c2Num + num2);
//        }
//    }
//    return max(c1Res, c2Res);
    long long c1Num = 0ll, c2Num = 0ll, currNum = 0ll;
    char c1 = pattern[0], c2 = pattern[1];
    for (size_t i = 0; i < text.size(); i++) {
        if (text[i] == c2) {
            currNum += c1Num;
            c2Num++;
        }
        if (text[i] == c1) {
            c1Num++;
        }
    }
    return currNum + max(c1Num, c2Num);
}

