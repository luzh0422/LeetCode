//
// Created by luzh on 2021/11/10.
//

#include "Solution495.h"

int Solution495::findPoisonedDuration(vector<int> &timeSeries, int duration) {
    int n = timeSeries.size();
    if (n == 0) {
        return 0;
    }
    int ans = 0;
    int currEnd = timeSeries[0] + duration;
    for (int i = 1; i < n; i++) {
       if (timeSeries[i] > currEnd) {
           ans += currEnd - timeSeries[i - 1];
       } else {
           ans += timeSeries[i] - timeSeries[i - 1];
       }
       currEnd = timeSeries[i] + duration;
    }
    return ans + duration;
}
