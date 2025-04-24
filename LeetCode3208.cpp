//
// Created by luzehui on 24-11-27.
//

#include "LeetCode3208.h"

int LeetCode3208::numberOfAlternatingGroups(vector<int> &colors, int k) {
    int index = 0, n = colors.size(), res = 0;
    bool tag = false;
    while (index < n) {
        int currIndex = index;
        if (tag) {
            if ((colors[currIndex + k - 2] ^ colors[currIndex + k - 1]) == 0) {
                tag = false;
            }
        } else {
            tag = true;
            for (int i = 1; i < k - 1; i++) {
                int nextIndex = (currIndex + 1) % n;
                int nextNextIndex = (nextIndex + 1) % n;
                if ((colors[currIndex] ^ colors[nextIndex]) == 0 ||
                    (colors[nextIndex] ^ colors[nextNextIndex]) == 0) {
                    tag = false;
                    break;
                }
                currIndex = (currIndex + 1) % n;
            }
        }
        if (tag) {
            res++;
        }
        index++;
    }
    return res;
}
