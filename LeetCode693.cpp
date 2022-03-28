//
// Created by luzh on 2022/3/28.
//

#include "LeetCode693.h"

bool LeetCode693::hasAlternatingBits(int n) {
    int lastBit = n % 2;
    n /= 2;
    while (n != 0) {
        int currBit = n % 2;
        if (lastBit == currBit) {
            return false;
        }
        lastBit = currBit;
        n /= 2;
    }
    return true;
}
