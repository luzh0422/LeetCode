//
// Created by 陆泽辉 on 2022/12/28.
//

#include "LeetCode1750.h"

int LeetCode1750::minimumLength(string s) {
    int left = 0, right = s.size() - 1;
    while (left < right) {
        if (s[left] != s[right]) {
            break;
        }
        char c = s[left];
        while (left < right && s[left] == c) {
            left++;
        }
        while (left <= right && s[right] == c) {
            right--;
        }
    }
    return right - left + 1;
}
