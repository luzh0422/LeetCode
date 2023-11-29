//
// Created by 陆泽辉 on 2023/6/17.
//

#include "LeetCode2481.h"

int LeetCode2481::numberOfCuts(int n) {
    if (n % 2 == 0) {
        return n / 2;
    } else {
        return n;
    }
}
