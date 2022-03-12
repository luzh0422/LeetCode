//
// Created by luzh on 2021/6/16.
//

#ifndef LEETCODE_SOLUTION877_H
#define LEETCODE_SOLUTION877_H

#include <vector>

using namespace std;

class Solution877 {
public:
    Solution877() {};
    bool stoneGame(vector<int>& piles);

private:
    bool alexStoneGame(vector<int>& piles, vector<int>& record, int alexStones, int liStones, int pickNum);
    bool liStoneGame(vector<int>& piles, vector<int>& record, int alexStones, int liStones, int pickNum);
};


#endif //LEETCODE_SOLUTION877_H
