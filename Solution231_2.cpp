//
// Created by luzh on 2021/5/30.
//

#include "Solution231_2.h"

bool Solution231_2::isPowerOfTwo(int n) {
    return (n & (n -1)) == 0;
}
