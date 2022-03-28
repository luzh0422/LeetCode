//
// Created by luzh on 2022/3/18.
//

#ifndef LEETCODE_LEETCODE2043_H
#define LEETCODE_LEETCODE2043_H

#include <vector>

using namespace std;

class Bank {
public:
    Bank(vector<long long>& balance);
    bool transfer(int account1, int account2, long long money);
    bool deposit(int account, long long money);
    bool withdraw(int account, long long money);

private:
    vector<long long> mBalance;
    int mSize = 0;
};


#endif //LEETCODE_LEETCODE2043_H
