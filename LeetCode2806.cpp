//
// Created by luzehui on 2024/6/12.
//

#include "LeetCode2806.h"

int LeetCode2806::accountBalanceAfterPurchase(int purchaseAmount) {
    if (purchaseAmount < 5) {
        return 100;
    }
    if (purchaseAmount <= 10) {
        return 90;
    }
    if (purchaseAmount == 100) {
        return 0;
    }
    int num1 = purchaseAmount % 10;
    purchaseAmount /= 10;
    int num2 = purchaseAmount % 10;
    if (num1 < 5) {
        return 100 - num2 * 10;
    }
    return 100 - (num2 + 1) * 10;
}
