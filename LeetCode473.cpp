//
// Created by 陆泽辉 on 2022/6/1.
//

#include "LeetCode473.h"
#include <algorithm>
#include <numeric>

bool LeetCode473::makesquare(vector<int> &matchsticks) {
    int totalLen = accumulate(matchsticks.begin(), matchsticks.end(), 0);
    if (totalLen % 4 != 0) {
        return false;
    }
    sort(matchsticks.begin(), matchsticks.end(), greater<int>());

    vector<int> edges(4);
    return makesquare(0, matchsticks, edges, totalLen / 4);
}

/**
 * 用 edges 来记录 4 条边已经放入的火柴总长度。对于第 index 火柴，尝试把它放入其中一条边内且满足放入后该边的火柴总长度不超过 len，然后继续枚举第 index+1 根火柴的放置情况，如果所有火柴都已经被放置，那么说明可以拼成正方形。
 * @param matchsticks
 * @return
 */
bool LeetCode473::makesquare(int index, vector<int> &matchsticks, vector<int> &edges, int len) {
    if (index == matchsticks.size()) {
        return true;
    }
    for (int i = 0; i < 4; i++) {
        edges[i] += matchsticks[index];
        if (edges[i] <= len && makesquare(index + 1, matchsticks, edges, len)) {
            return true;
        }
        edges[i] -= matchsticks[index];
    }
    return false;
}
