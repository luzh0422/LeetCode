//
// Created by luzh on 2021/9/19.
//

#include "Solution650.h"

#include <vector>

using namespace std;

int Solution650::minSteps(int n) {
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    dp[1] = 0;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j * j <= i; j++) {
            if (i % j == 0) {
                dp[i] = min(dp[i], dp[j] + i / j);
                dp[i] = min(dp[i], dp[i / j] + j);
            }
        }
    }
    return dp[n];
}
