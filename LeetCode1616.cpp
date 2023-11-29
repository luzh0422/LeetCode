//
// Created by 陆泽辉 on 2023/3/18.
//

#include "LeetCode1616.h"

bool LeetCode1616::checkPalindromeFormation(string a, string b) {
    return checkPalindromeFormationHelper(a, b) || checkPalindromeFormationHelper(b, a);
}

bool LeetCode1616::checkPalindromeFormationHelper(string a, string b) {
    if (a == string(a.rbegin(), a.rend())) {
        return true;
    }
    int i = 0, j = a.size() - 1;
    while (i <= j && a[i] == b[j]) {
        i++;
        j--;
    }
    if (i >= j) {
        return true;
    }
    int left = i, right = j;
    while (left <= right && a[left] == a[right]) {
        left++;
        right--;
    }
    if (left >= right) {
        return true;
    }
    left = i, right = j;
    while (left <= right && b[left] == b[right]) {
        left++;
        right--;
    }
    if (left >= right) {
        return true;
    }
    return false;
}
