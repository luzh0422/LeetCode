//
// Created by 陆泽辉 on 2022/6/30.
//

#ifndef LEETCODE_LEETCODE1175_H
#define LEETCODE_LEETCODE1175_H


class LeetCode1175 {
public:
    int numPrimeArrangements(int n);

private:
    bool isPrime(int num);
    int countHelper(int num);
};


#endif //LEETCODE_LEETCODE1175_H
