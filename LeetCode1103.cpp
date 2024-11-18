//
// Created by luzehui on 2024/6/3.
//

#include "LeetCode1103.h"

vector<int> LeetCode1103::distributeCandies(int candies, int num_people) {
    int t = 0, n = num_people;
    vector<int> res(n);
    while (n * (n + 1) / 2 + t * n * n <= candies) {
        candies -= n * (n + 1) / 2 + t * n * n;
        t++;
    }
    for (int i = 0; i < n; i++) {
        res[i] = (i + 1) * t + (t - 1) * t / 2 * n;
        if (candies >= t * n + i + 1) {
            res[i] += t * n + i + 1;
            candies -= t * n + i + 1;
        } else {
            res[i] += candies;
            candies = 0;
        }
    }
    return res;
}
