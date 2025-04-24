//
// Created by luzehui on 25-2-14.
//

#include "LeetCode1552.h"

int LeetCode1552::maxDistance(vector<int> &position, int m) {
    std::sort(position.begin(), position.end());
    int left = 1, right = position.back();
    while (left < right) {
        int middle = (left + right + 1) / 2;
        int pre = 0, cnt = m - 1;
        for (int i = 1; i < position.size(); i++) {
            if (position[i] - position[pre] >= middle) {
                pre = i;
                if (--cnt <= 0) {
                    break;
                }
            }
        }
        if (cnt > 0) {
            right = middle - 1;
        } else {
            left = middle;
        }
    }
    return right;
}
