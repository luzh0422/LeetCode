//
// Created by 陆泽辉 on 2022/11/10.
//

#include "LeetCode754.h"
#include <algorithm>

int LeetCode754::reachNumber(int target) {
    target = std::abs(target);
    int k = 0;
    while (target > 0 || target % 2 != 0) {
        target -= ++k;
    }
    return k;
}
