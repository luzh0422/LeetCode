//
// Created by 陆泽辉 on 2023/9/25.
//

#include "LeetCode2591.h"

int LeetCode2591::distMoney(int money, int children) {
    int res = 0;
    int totalMoney = money, totalChildren = children;
    while (children > 1 && money >= children + 7) {
        money -= 8;
        children--;
        res++;
    }
    if (children == 1) {
        if (money == 4) {
            res--;
        } else if (money == 8) {
            res++;
        }
    }
    return totalMoney < totalChildren ? -1 : res;
}
