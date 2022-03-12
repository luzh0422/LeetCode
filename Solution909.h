//
// Created by luzh on 2021/6/27.
//

#ifndef LEETCODE_SOLUTION909_H
#define LEETCODE_SOLUTION909_H

#include <vector>

using namespace std;

class Solution909 {
public:
    int snakesAndLadders(vector<vector<int>>& board);

private:
    pair<int, int> id2rc(int id, int n);
};


#endif //LEETCODE_SOLUTION909_H
