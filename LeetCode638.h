//
// Created by luzehui on 2024/11/8.
//

#ifndef LEETCODE_LEETCODE638_H
#define LEETCODE_LEETCODE638_H

#include <vector>

using namespace std;

class LeetCode638 {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs);

private:
    bool canUseThisSp(vector<int>& sp, vector<int>& needs);
};


#endif //LEETCODE_LEETCODE638_H
