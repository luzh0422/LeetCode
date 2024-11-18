//
// Created by luzehui on 2024/10/24.
//

#include "LeetCode3175.h"
#include <queue>

int LeetCode3175::findWinningPlayer(vector<int> &skills, int k) {
    queue<pair<int, int>> q{};
    int curr = skills[0], currIndex = 0, count = 0, n = skills.size();
    if (n < k) {
        return distance(skills.begin(), max_element(skills.begin(), skills.end()));
    }
    for (int i = 1; i < n; i++) {
        q.push({skills[i], i});
    }
    while (count < k) {
        auto next = q.front().first;
        auto nextIndex = q.front().second;
        q.pop();
        if (curr >= next) {
            q.push({next, nextIndex});
            count++;
        } else {
            q.push({curr, currIndex});
            curr = next;
            currIndex = nextIndex;
            count = 1;
        }
    }
    return currIndex;
}
