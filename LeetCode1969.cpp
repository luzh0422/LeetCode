//
// Created by luzehui on 2024/3/20.
//

#include "LeetCode1969.h"
#include <numeric>

using namespace std;

unsigned long long fastPow(unsigned long long base, unsigned long long power, unsigned long long mod) {
    unsigned long long result = 1;
    base %= mod;

    for (unsigned long long i = power; i > 0; i /= 2) {
        if (i % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
    }

    return result;
}

int LeetCode1969::minNonZeroProduct(int p) {
    const unsigned long long MOD = 1e9 + 7;
    unsigned long long num1 = ((1ll << p) - 1) % MOD;
    unsigned long long num2 = (1ll << p) - 2;
    unsigned long long num3 = (1ll << (p - 1)) - 1;
    unsigned long long res = fastPow(num2, num3, MOD);
    res %= MOD;
    res = num1 * res;
    res %= MOD;
    return res;
}
