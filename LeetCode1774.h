//
// Created by 陆泽辉 on 2022/12/4.
//

#ifndef LEETCODE_LEETCODE1774_H
#define LEETCODE_LEETCODE1774_H

#include <vector>

using namespace std;

class LeetCode1774 {
public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target);

private:
    int closestCost(int cost, vector<int>& toppingCosts, int target, int index);
    int closestCostHelper(int costA, int costB, int target);
};


#endif //LEETCODE_LEETCODE1774_H
