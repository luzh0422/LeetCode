//
// Created by luzehui on 2024/11/26.
//

#include "LeetCode3206.h"

int LeetCode3206::numberOfAlternatingGroups(vector<int> &colors) {
    int res = 0, index = 0, n = colors.size();
    while (index < n) {
        int nextIndex = (index + 1) % n, nextNextIndex = (index + 2) % n;
        if ((colors[index] ^ colors[nextIndex]) == 1 && (colors[nextIndex] ^ colors[nextNextIndex]) == 1) {
            res++;
        }
        index++;
    }
    return res;
}
