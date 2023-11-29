//
// Created by 陆泽辉 on 2022/4/5.
//

#ifndef LEETCODE_LEETCODE762_H
#define LEETCODE_LEETCODE762_H

#include <unordered_set>

using namespace std;

class LeetCode762 {
public:
    int countPrimeSetBits(int left, int right);

private:
    bool isPrime(int num);
    int getBis(int num);
    unordered_set<int> primes = {};
};


#endif //LEETCODE_LEETCODE762_H
