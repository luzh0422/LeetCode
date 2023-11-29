//
// Created by 陆泽辉 on 2023/6/26.
//

#include "LeetCode2485.h"

int LeetCode2485::pivotInteger(int n) {
    int total = (n + 1) * n / 2;
    int curr = 0;
    for (int i = n; i > 0; i--) {
        curr += i;
        if (curr == total - curr + i) {
            return i;
        }
        if (curr > total / 2) {
            break;
        }
    }
    return -1;
}
