//
// Created by luzehui on 2024/6/27.
//

#include "LeetCode2734.h"

string LeetCode2734::smallestString(std::string s) {
    size_t index = 0, n = s.size();
    int count = 0;
    while (index < n - 1 && s[index] == 'a') {
        index++;
    }
    while (index < n && s[index] != 'a') {
        s[index++]--;
        count = 1;
    }
    if (count == 0) {
        s[index] = 'z';
    }
    return s;
}
