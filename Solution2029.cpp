//
// Created by luzh on 2022/1/20.
//

#include "Solution2029.h"

bool Solution2029::stoneGameIX(vector<int> &stones) {
    int cnt0 = 0, cnt1 = 0, cnt2 = 0;
    int n = stones.size();
    for (int i = 0; i < n; i++) {
        int stone = stones[i];
        if (stone % 3 == 0) {
            cnt0++;
        } else if (stone % 3 == 1) {
            cnt1++;
        } else {
            cnt2++;
        }
    }
    if (cnt0 % 2 == 0) {
        return cnt1 >= 1 && cnt2 >= 1;
    } else {
        return abs(cnt1 - cnt2) > 2;
    }
}
