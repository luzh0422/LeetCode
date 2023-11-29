//
// Created by 陆泽辉 on 2022/8/23.
//

#ifndef LEETCODE_LEETCODE782_H
#define LEETCODE_LEETCODE782_H

#include <vector>

using namespace std;

class LeetCode782 {
public:
    int movesToChessboard(vector<vector<int>>& board);

private:
    int getMoves(int mask, int count, int n);
};

#endif //LEETCODE_LEETCODE782_H
