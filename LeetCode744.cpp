//
// Created by 陆泽辉 on 2022/4/3.
//

#include "LeetCode744.h"

char LeetCode744::nextGreatestLetter(vector<char> &letters, char target) {
    int n = letters.size();
    char ret = letters[0];
    for (int i = 0; i < n; i++) {
        if (letters[i] > target) {
            ret = letters[i];
            break;
        }
    }
    return ret;
}
