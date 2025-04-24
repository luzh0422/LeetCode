//
// Created by luzehui on 25-4-13.
//

#include "LeetCode1992.h"
#include <cmath>
#include <functional>

int LeetCode1992::countGoodNumbers(long long n) {
    const int MOD = 1e9 + 7;
    long long evenBits = (n + 1) / 2;
    long long oddBis = n / 2;
    std::function<long long(int, long long)> quickPowHelper = [&](int num, long long bits) -> int {
        if (bits == 0) {
            return 1;
        }
        long long y = quickPowHelper(num, bits / 2) % MOD;
        long long res = (bits & 1) == 0 ? y * y : y * y * num;
        res %= MOD;
        return res;
    };
    return quickPowHelper(5, evenBits) * quickPowHelper(4, oddBis) % MOD;
}
