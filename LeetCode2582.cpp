//
// Created by 陆泽辉 on 2023/9/26.
//

#include "LeetCode2582.h"

int LeetCode2582::passThePillow(int n, int time) {
    int delta = time % (n - 1);
    int loop = time / (n - 1);
    if (loop % 2 == 0) {
        return delta + 1;
    }
    return n - delta;
}
