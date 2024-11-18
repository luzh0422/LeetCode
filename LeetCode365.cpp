//
// Created by luzehui on 2024/1/28.
//

#include "LeetCode365.h"
#include <unordered_set>
#include <stack>

using namespace std;

using PII = pair<int, int>;

bool LeetCode365::canMeasureWater(int x, int y, int z) {
    stack<PII> stk;
    stk.emplace(0, 0);
    auto hashFunction = [](const PII& o) -> int {
        return hash<int>()(o.first) ^ hash<int>()(o.second);
    };
    unordered_set<PII, decltype(hashFunction)> sceen(0, hashFunction);
    while (!stk.empty()) {
        if (sceen.count(stk.top())) {
            stk.pop();
            continue;
        }
        sceen.emplace(stk.top());
        auto [remain_x, remain_y] = stk.top();
        stk.pop();
        if (remain_x == z || remain_y == z || remain_x + remain_y == z) {
            return true;
        }
        // 把x壶灌满；
        stk.emplace(x, remain_y);
        // 把y壶灌满；
        stk.emplace(remain_x, y);
        // 把x壶清空；
        stk.emplace(0, remain_y);
        // 把y壶清空；
        stk.emplace(remain_x, 0);
        // 把x壶的水灌到y壶；
        stk.emplace(remain_x - min(remain_x, y - remain_y), remain_y + min(remain_x, y - remain_y));
        // 把y壶的水灌到x壶；
        stk.emplace(remain_x + min(remain_y, x - remain_x), remain_y - min(remain_y, x - remain_x));
    }
    return false;
}
