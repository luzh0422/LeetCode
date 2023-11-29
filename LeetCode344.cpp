//
// Created by 陆泽辉 on 2023/8/7.
//

#include "LeetCode344.h"

void LeetCode344::reverseString(vector<char> &s) {
    int left = 0, right = s.size() - 1;
    while (left < right) {
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }
    return;
}
