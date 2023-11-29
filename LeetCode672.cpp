//
// Created by 陆泽辉 on 2022/9/15.
//

#include "LeetCode672.h"

#include <algorithm>
#include <vector>
#include <unordered_set>

using namespace std;

int LeetCode672::flipLights(int n, int presses) {
    n = min(n, 6);
    vector<int> ops = {0b111111, 0b010101, 0b101010, 0b100100};
    unordered_set<int> vis;
    /**
     * 总共有4个按钮，每个按钮分为操作奇数次、偶数次，因此一共有16种按钮选择；
     * 按钮操作技术次，对灯光有影响。
     * 按钮操作偶数次，对灯光没有影响。
     */
    for (int mask = 0; mask < 1 << 4; ++mask) {
        int cnt = __builtin_popcount(mask);
        if (cnt > presses || cnt % 2 != presses % 2) continue;
        int t = 0;
        for (int i = 0; i < 4; ++i) {
            /**
             * 判断是否对应的按钮有操作；
             */
            if ((mask >> i) & 1) {
                t ^= ops[i];
            }
        }
        /**
         * 初始所有等都打开，所以初始值为 1 << 6 - 1;
         */
        t &= (1 << 6) - 1;
        /**
         * 假设没有这么多灯光，所以要移除不存在的灯光；
         */
        t >>= (6 - n);
        vis.insert(t);
    }
    return vis.size();
}
