//
// Created by luzehui on 2024/3/9.
//

#include "LeetCode2834.h"

int LeetCode2834::minimumPossibleSum(int n, int target) {
    const int MOD = 1e9 + 7;
    if (n <= target / 2) {
        return n * (n + 1) / 2 % MOD;
    }
    long long temp = target / 2;
    long long num1 = temp * (temp + 1) / 2 % MOD;
    long long step = n - temp;
    long long num2 = (target * step) + (step) * (step - 1) / 2 % MOD;
    return (num1 + num2) % MOD;
}
