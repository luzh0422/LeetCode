//
// Created by 陆泽辉 on 2022/12/9.
//

#include "LeetCode1780.h"

bool LeetCode1780::checkPowersOfThree(int n) {
    while (n > 0) {
        if (n % 3 == 2) {
            return false;
        }
        n /= 3;
    }
    return true;
}
