//
// Created by luzh on 2022/1/15.
//

#include "Solution1716.h"

int Solution1716::totalMoney(int n) {
    int weekNums = n / 7;
    int dayNums = n % 7;
    int total = (7 + 1) * 7 / 2 * weekNums;
    total += 7 * (weekNums - 1) * weekNums / 2;
    total += weekNums * dayNums;
    total += (dayNums + 1) * dayNums / 2;
    return total;
}
