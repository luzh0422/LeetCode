//
// Created by 陆泽辉 on 2022/11/11.
//

#include "LeetCode1704.h"

#include <unordered_set>

bool LeetCode1704::halvesAreAlike(string s) {
    int left = 0, right = s.size() - 1;
    int leftCount = 0, rightCount = 0;
    unordered_set<char> dictionary = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    while (left <= right) {
        if (dictionary.count(s[left])) {
            leftCount++;
        }
        if (dictionary.count(s[right])) {
            rightCount++;
        }
        left++;
        right--;
    }
    return leftCount == rightCount;
}
