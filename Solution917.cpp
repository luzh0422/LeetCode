//
// Created by luzh on 2022/2/23.
//

#include "Solution917.h"

string Solution917::reverseOnlyLetters(string s) {
    int left = 0, right = s.size() - 1;
    while (left < s.size() && !(s[left] >= 'a' && s[left] <= 'z' || s[left] >= 'A' || s[left] <= 'Z')) {
        left++;
    }
    while (right >= 0 && !(s[right] >= 'a' && s[right] <= 'z' || s[right] >= 'A' || s[right] <= 'Z')) {
        right--;
    }
    while (left < right) {
        char c = s[left];
        s[left] = s[right];
        s[right] = c;
        left++;
        right--;
        while (left < right && !(s[left] >= 'a' && s[left] <= 'z' || s[left] >= 'A' && s[left] <= 'Z')) {
            left++;
        }
        while (left < right && !(s[right] >= 'a' && s[right] <= 'z' || s[right] >= 'A' && s[right] <= 'Z')) {
            right--;
        }
    }
    return s;
}
