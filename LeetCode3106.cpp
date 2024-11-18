//
// Created by luzehui on 2024/7/27.
//

#include "LeetCode3106.h"

string LeetCode3106::getSmallestString(std::string s, int k) {
    for (char& c : s) {
        int distance = min('z' - c + 1, c - 'a');
        if (distance <= k) {
            c = 'a';
            k -= distance;
        } else {
            int curr = c - 'a';
            int target = min(curr - k, (curr + k) % 26);
            c = 'a' + target;
            break;
        }
        if (k == 0) {
            break;
        }
    }
    return s;
}
