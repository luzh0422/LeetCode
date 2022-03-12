//
// Created by luzh on 2021/9/4.
//

#include "SolutionOffer10_1.h"
#include <vector>

using namespace std;

int SolutionOffer10_1::fib(int n) {
    vector<int> fib(n + 1);
    if (n <= 1) {
        return n;
    }
    const int MOD = 1000000007;
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= n; i++) {
        fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;
    }
    return fib[n];
}
