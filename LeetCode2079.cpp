//
// Created by luzehui on 2024/5/8.
//

#include "LeetCode2079.h"

int LeetCode2079::wateringPlants(vector<int> &plants, int capacity) {
    int res = 0, n = plants.size();
    int currCapacity = capacity;
    for (int i = 0; i < n; i++) {
        res++;
        currCapacity -= plants[i];
        if (i < n - 1 && plants[i + 1] > currCapacity) {
            res += (i + 1) * 2;
            currCapacity = capacity;
        }
    }
    return res;
}
