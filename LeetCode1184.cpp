//
// Created by 陆泽辉 on 2022/7/24.
//

#include "LeetCode1184.h"
#include <numeric>

int LeetCode1184::distanceBetweenBusStops(vector<int> &distance, int start, int destination) {
    int totalSum = accumulate(distance.begin(), distance.end(), 0);
    int ret = 0;
    int beginPoint = min(start, destination);
    int endPoint = max(start, destination);
    for (int i = beginPoint; i < endPoint; i++) {
        ret += distance[i];
    }
    ret = min(ret, totalSum - ret);
    return ret;
}
