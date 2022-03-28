//
// Created by luzh on 2022/3/18.
//

#include "LeetCode2043.h"

Bank::Bank(vector<long long> &balance) {
    mBalance = balance;
    mSize = mBalance.size();
}

bool Bank::transfer(int account1, int account2, long long money) {
    if (account1 > mSize || account2 > mSize || mBalance[account1 - 1] < money) {
        return false;
    }
    mBalance[account1 - 1] -= money;
    mBalance[account2 - 1] += money;
    return true;
}

bool Bank::deposit(int account, long long money) {
    if (account > mSize) {
        return false;
    }
    mBalance[account - 1] += money;
    return true;
}

bool Bank::withdraw(int account, long long money) {
    if (account > mSize || mBalance[account - 1] < money) {
        return false;
    }
    mBalance[account - 1] -= money;
    return true;
}

