//
// Created by luzh on 2021/11/1.
//

#include "Solution575.h"
#include <algorithm>
#include <set>

int Solution575::distributeCandies(vector<int> &candyType) {
    set<int> s;
    int count = 0;
    for (auto candy : candyType) {
        if (!s.count(candy)) {
            count++;
            s.emplace(candy);
        }
    }
    return min(count, int(candyType.size() / 2));
}
