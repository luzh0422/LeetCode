//
// Created by luzh on 2021/11/4.
//

#include "Solution367.h"

bool Solution367::isPerfectSquare(int num) {
    long long res = 0;
    while (res * res <= num) {
        if (res * res == num) {
            return true;
        }
        res++;
    }
    return false;
}
