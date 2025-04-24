//
// Created by luzehui on 25-4-20.
//

#include "LeetCode781.h"
#include <unordered_map>

int LeetCode781::numRabbits(vector<int> &answers) {
    unordered_map<int, int> cache{};
    for (auto num : answers) {
        cache[num]++;
    }
    int res = 0;
    for (auto& iter : cache) {
        int num = iter.first;
        int count = (iter.second + num) % (num + 1);
        res += (num + 1) * count;
    }
    return res;
}
