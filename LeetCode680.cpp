//
// Created by luzehui on 25-2-3.
//

#include "LeetCode680.h"

bool LeetCode680::validPalindrome(std::string s) {
    int left = 0, right = s.size() - 1;
    while (left < right) {
        if (s[left] != s[right]) {
            string leftString = s.substr(left, right - left);
            string rightString = s.substr(left + 1, right - left);
            return isPalindrome(leftString) || isPalindrome(rightString);
        }
        left++;
        right--;
    }
    return true;
}

bool LeetCode680::isPalindrome(std::string &s) {
    int left = 0, right = s.size() - 1;
    while (left < right) {
        if (s[left] != s[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}
