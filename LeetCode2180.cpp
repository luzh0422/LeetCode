//
// Created by 陆泽辉 on 2023/1/6.
//

#include "LeetCode2180.h"

int LeetCode2180::countEven(int num) {
    int res = 0;
    for (int i = 1; i <= num; i++) {
        int count = countNum(i);
        if (count % 2 == 0) {
            res++;
        }
    }
    return res;
}

int LeetCode2180::countNum(int num) {
    int count = 0;
    while (num > 0) {
        count += (num % 10);
        num /= 10;
    }
    return count;
}
