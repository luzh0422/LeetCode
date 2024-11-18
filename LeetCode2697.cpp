//
// Created by luzehui on 2023/12/13.
//

#include "LeetCode2697.h"

string LeetCode2697::makeSmallestPalindrome(std::string s) {
    int left = 0, right = s.size() - 1;
    while (left < right) {
        if (s[left] < s[right]) {
            s[right] = s[left];
        } else if (s[left] > s[right]) {
            s[left] = s[right];
        }
        left++;
        right--;
    }
    return s;
}
