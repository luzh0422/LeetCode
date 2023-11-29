//
// Created by 陆泽辉 on 2023/7/22.
//

#include "LeetCode860.h"

bool LeetCode860::lemonadeChange(vector<int> &bills) {
    int fiveCount = 0, tenCount = 0;
    for (auto& bill : bills) {
        if (bill == 5) {
            fiveCount++;
        } else if (bill == 10) {
            if (fiveCount <= 0) {
                return false;
            }
            fiveCount--;
            tenCount++;
        } else {
            if (tenCount > 0) {
                if (fiveCount > 0) {
                    tenCount--;
                    fiveCount--;
                } else {
                    return false;
                }
            } else if (fiveCount >= 3) {
                fiveCount -= 3;
            } else {
                return false;
            }
        }
    }
    return true;
}
