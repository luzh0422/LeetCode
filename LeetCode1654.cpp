//
// Created by 陆泽辉 on 2023/8/30.
//

#include "LeetCode1654.h"
#include <unordered_set>
#include <queue>
#include <tuple>

int LeetCode1654::minimumJumps(vector<int> &forbidden, int a, int b, int x) {
    queue<tuple<int, int, int>> q;
    unordered_set<int> visited;
    q.emplace(0, 1, 0);
    visited.emplace(0);
    int lower = 0, upper = max(*max_element(forbidden.begin(), forbidden.end()) + a, x) + b;
    unordered_set<int> forbiddenSet(forbidden.begin(), forbidden.end());
    while (!q.empty()) {
        auto [position, direction, step] = q.front();
        q.pop();
        if (position == x) {
            return step;
        }
        int nextPosition = position + a;
        int nextDierecton = 1;
        if (lower <= nextPosition && nextPosition <= upper && !visited.count(nextPosition * nextDierecton) && !forbiddenSet.count(nextPosition)) {
            visited.emplace(nextPosition * nextDierecton);
            q.emplace(nextPosition, nextDierecton, step + 1);
        }
        if (direction == 1) {
            nextPosition = position - b;
            nextDierecton = -1;
            if (lower <= nextPosition && nextPosition <= upper && !visited.count(nextPosition * nextDierecton) && !forbiddenSet.count(nextPosition)) {
                visited.emplace(nextPosition * nextDierecton);
                q.emplace(nextPosition, nextDierecton, step + 1);
            }
        }
    }
    return -1;
}
