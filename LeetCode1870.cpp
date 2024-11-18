//
// Created by luzehui on 2024/10/2.
//

#include "LeetCode1870.h"

int LeetCode1870::minSpeedOnTime(vector<int> &dist, double hour) {
    int left = 1, right = 1e7;
    double totalTime = 0.0;
    while (left < right) {
        int middle = (left + right) / 2;
        totalTime = getTotalTime(dist, middle);
        if (totalTime > hour) {
            left = middle + 1;
        } else if (totalTime <= hour) {
            right = middle;
        }
    }
    return totalTime > hour ? -1 : left;
}

double LeetCode1870::getTotalTime(vector<int> &dist, int speed) {
    int n = dist.size();
    int res1 = 0;
    double res = 0.0;
    for (int i = 0; i < n - 1; i++) {
        res1 += (dist[i] + speed - 1) / speed;
    }
    res = (double)res1 + double(dist[n - 1]) / double(speed);
    return res;
}
