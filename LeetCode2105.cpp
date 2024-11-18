//
// Created by luzehui on 2024/5/9.
//

#include "LeetCode2105.h"

int LeetCode2105::minimumRefill(vector<int> &plants, int capacityA, int capacityB) {
    int left = 0, right = plants.size() - 1, res = 0;
    int currCapacityA = capacityA, currCapacityB = capacityB;
    while (left < right) {
        if (currCapacityA >= plants[left]) {
            currCapacityA -= plants[left];
        } else {
            res++;
            currCapacityA = capacityA - plants[left];
        }
        if (currCapacityB >= plants[right]) {
            currCapacityB -= plants[right];
        } else {
            res++;
            currCapacityB = capacityB - plants[right];
        }
        left++;
        right--;
    }
    if (left == right) {
        int maxCurrCapacity = max(currCapacityA, currCapacityB);
        if (maxCurrCapacity < plants[left]) {
            res++;
        }
    }
    return res;
}
