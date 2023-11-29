//
// Created by 陆泽辉 on 2023/4/21.
//

#include "LeetCode2413.h"

int LeetCode2413::smallestEvenMultiple(int n) {
    if (n % 2 == 0) {
        return n;
    }
    return 2 * n;
}
