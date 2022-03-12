//
// Created by luzh on 2021/9/23.
//

#include "Solution326.h"

bool Solution326::isPowerOfThree(int n) {
    if (n <= 0) return false;
    while (n > 0) {
        if (n % 3 != 0 && n != 1) {
            return false;
        }
        n /= 3;
    }
    return true;
}
