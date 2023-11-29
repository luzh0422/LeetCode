//
// Created by 陆泽辉 on 2022/12/4.
//

#include "LeetCode1774.h"

int LeetCode1774::closestCost(vector<int> &baseCosts, vector<int> &toppingCosts, int target) {
    int ret = 0;
    int minDistance = INT_MAX;
    for (auto baseCost : baseCosts) {
        int cost = closestCost(baseCost, toppingCosts, target, 0);
        int distance = abs(cost - target);
        if (distance < minDistance) {
            minDistance = distance;
            ret = cost;
        } else if (distance == minDistance && cost < ret) {
            ret = cost;
        }
    }
    return ret;
}

int LeetCode1774::closestCost(int cost, vector<int> &toppingCosts, int target, int index) {
    if (index == toppingCosts.size()) {
        return cost;
    }
    int a = closestCost(cost, toppingCosts, target, index + 1);
    int b = closestCost(cost + toppingCosts[index], toppingCosts, target, index + 1);
    int c = closestCost(cost + toppingCosts[index] * 2, toppingCosts, target, index + 1);
    int temp = closestCostHelper(cost, a, target);
    temp = closestCostHelper(temp, b, target);
    temp = closestCostHelper(temp, c, target);
    return temp;
}

int LeetCode1774::closestCostHelper(int costA, int costB, int target) {
    int distanceA = abs(costA - target);
    int distanceB = abs(costB - target);
    if (distanceA < distanceB) {
        return costA;
    } else if (distanceA > distanceB) {
        return costB;
    } else {
        return min(costA, costB);
    }
}


