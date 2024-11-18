//
// Created by luzehui on 2024/10/14.
//

#include "LeetCode1884.h"
#include <vector>

using namespace std;

int LeetCode1884::twoEggDrop(int n) {
    vector<int> dp(n + 1, 0x3f3f3f3f);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        // 遍历每一个楼层，如果在这一层鸡蛋碎了，则数量为j - 1;
        // 如果鸡蛋没有碎，则为dp[i - j];
        for (int j = 1; j <= i; j++) {
            dp[i] = min(dp[i], max(j - 1, dp[i - j] + 1));
        }
    }
    return dp[n];
}
