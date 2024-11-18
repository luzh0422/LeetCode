//
// Created by luzehui on 2024/6/5.
//

#include "LeetCode2928.h"

#include <numeric>

using namespace std;

int LeetCode2928::distributeCandies(int n, int limit) {
    int ans = 0;
    for (int i = 0; i <= limit; i++) {
        for (int j = 0; j <= limit; j++) {
            if (i + j > n) {
                break;
            }
            if (n - i - j <= limit) {
                ans++;
            }
        }
    }
    return ans;
}
