//
// Created by luzh on 2021/9/26.
//

#include "Solution371.h"

int Solution371::getSum(int a, int b) {
    unsigned int unsignedA = a;
    unsigned int unsignedB = b;
    while (unsignedA != 0) {
        int t = unsignedB;
        unsignedB ^= unsignedA; // 不考虑进位时，a 与 b相加后的值；
        unsignedA = (t & unsignedA) << 1; // a 与 b相加时的进位值；
    }
    return unsignedB;
}
