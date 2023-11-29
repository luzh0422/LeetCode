//
// Created by 陆泽辉 on 2023/7/24.
//

#include "LeetCode771.h"

#include <unordered_set>

int LeetCode771::numJewelsInStones(string jewels, string stones) {
    unordered_set<char> uS;
    for (char c : jewels) {
        uS.insert(c);
    }
    int res = 0;
    for (char c : stones) {
        if (uS.count(c)) {
            res++;
        }
    }
    return res;
}
