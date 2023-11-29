//
// Created by 陆泽辉 on 2022/6/30.
//

#include "LeetCode1175.h"
const int MOD = 100000007;

int LeetCode1175::numPrimeArrangements(int n) {
    int primeCount = 0, noPrimeCount = 0;

    for (int i = 1; i <= n; i++) {
        if (isPrime(i)) {
            primeCount++;
        } else {
            noPrimeCount++;
        }
    }
    int ret = countHelper(primeCount) * countHelper(noPrimeCount) % MOD;
    return ret;
}

bool LeetCode1175::isPrime(int num) {
    if (num == 1) {
        return false;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int LeetCode1175::countHelper(int num) {
    if (num == 0) {
        return 0;
    }
    int ret = 1;
    for (int i = 1; i <= num; i++) {
        ret *= i;
        ret % MOD;
    }
    return ret;
}
