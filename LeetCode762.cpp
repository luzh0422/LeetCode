//
// Created by 陆泽辉 on 2022/4/5.
//

#include "LeetCode762.h"

int LeetCode762::countPrimeSetBits(int left, int right) {
    int ret = 0;
    for (int i = left; i <= right; i++) {
        int num = getBis(i);
        if (isPrime(num)) {
            ret++;
        }
    }
    return ret;
}

int LeetCode762::getBis(int num) {
    int bits = 0;
    while (num != 0) {
        if (num % 2 != 0) {
            bits++;
        }
        num /= 2;
    }
    return bits;
}

bool LeetCode762::isPrime(int num) {
    if (this->primes.count(num)) {
        return true;
    }
    if (num == 1) {
        return false;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    this->primes.insert(num);
    return true;
}
