//
// Created by luzh on 2021/8/30.
//

#include "Solution528.h"

Solution528::Solution528(vector<int> &w) {
    int size = w.size();
    int preTotal = 0;
    for (int i = 0; i < size; i++) {
        preTotal += w[i];
        pre.push_back(preTotal);
    }
}

/**
 * pre[i] - w[i] + 1 <= x <= pre[i];
 * 取一个随机数x，确定i的位置即可。
 * @return
 */
int Solution528::pickIndex() {
    int total = pre.back();
    int randNum = random() % total + 1;
    int index = lower_bound(pre.begin(), pre.end(), randNum) - pre.begin();
    return index;
}
