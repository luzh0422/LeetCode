//
// Created by 陆泽辉 on 2023/1/3.
//

#include "LeetCode2042.h"

bool LeetCode2042::areNumbersAscending(string s) {
    int curr = 0;
    int index = 0, n = s.size();
    while (index < n) {
        if (s[index] >= '0' && s[index] <= '9') {
            int right = index + 1;
            while (right < n && s[right] >= '0' && s[right] <= '9') {
                right++;
            }
            string temp = s.substr(index, right);
            int next = stoi(temp);
            if (next <= curr) {
                return false;
            }
            curr = next;
            index = right;
        } else {
            index++;
        }
    }
    return true;
}


