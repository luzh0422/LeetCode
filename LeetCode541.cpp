//
// Created by luzehui on 25-1-31.
//

#include "LeetCode541.h"

string LeetCode541::reverseStr(std::string s, int k) {
    int index = 0, n = s.size();
    while (index < n) {
        int left = index, right = min(index + k - 1, n - 1);
        while (left < right) {
            char c = s[left];
            s[left] = s[right];
            s[right] = c;
            left++;
            right--;
        }
        index += 2 * k;
    }
    return s;
}
