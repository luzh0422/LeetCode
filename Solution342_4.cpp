//
// Created by luzh on 2021/5/31.
//

#include "Solution342_4.h"

bool Solution342_4::isPowerOfFour(int n) {
    return n > 0 && (n & (n - 1)) == 0 && (n & (0xaaaaaaaa)) == 0;
}
