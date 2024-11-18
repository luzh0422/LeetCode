//
// Created by luzehui on 2023/12/14.
//

#include "LeetCode70.h"

#include <unordered_map>

using namespace std;

unordered_map<int, int> uM{};

int LeetCode70::climbStairs(int n) {
    if (uM.count(n)) {
        return uM[n];
    }
    if (n == 1 || n == 0) {
        return 1;
    }
    if (n < 0) {
        return 0;
    }
    int res = climbStairs(n - 1) + climbStairs(n - 2);
    uM[n] = res;
    return res;
}
