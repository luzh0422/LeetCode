//
// Created by luzehui on 24-11-30.
//

#include "LeetCode3232.h"

bool LeetCode3232::canAliceWin(vector<int> &nums) {
    int cnt1 = 0, cnt2 = 0, total = 0;
    for (auto& num : nums) {
        if (num < 10) {
            cnt1 += num;
        } else if (num < 100) {
            cnt2 += num;
        }
        total += num;
    }
    return max(cnt1, cnt2) > total - max(cnt1, cnt2);
}
