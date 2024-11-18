//
// Created by luzehui on 2024/6/10.
//

#include "LeetCode881.h"

int LeetCode881::numRescueBoats(vector<int> &people, int limit) {
    std::sort(people.begin(), people.end());
    int res = 0;
    int l = 0, r = people.size() - 1;
    while (l <= r) {
        if (people[r] + people[l] > limit) {
            res++;
            r--;
        } else {
            l++;
            r--;
            res++;
        }
    }
    return res;
}
