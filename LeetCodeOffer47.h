//
// Created by 陆泽辉 on 2023/3/8.
//

#ifndef LEETCODE_LEETCODEOFFER47_H
#define LEETCODE_LEETCODEOFFER47_H

#include <vector>

using namespace std;

class LeetCodeOffer47 {
public:
    int maxValue(vector<vector<int>>& grid);

private:
    int backtrack(vector<vector<int>>& grid, vector<vector<int>>& visits, int currRow, int currCol, int n, int m);
};


#endif //LEETCODE_LEETCODEOFFER47_H
