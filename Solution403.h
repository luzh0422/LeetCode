//
// Created by luzh on 2021/4/29.
//

#ifndef LEETCODE_SOLUTION403_H
#define LEETCODE_SOLUTION403_H

#include <vector>

using namespace std;

class Solution403 {
public:
    Solution403() {}
    bool canCross(vector<int>& stones);

private:
    bool canCross(vector<int>& stones, int curr, int step);
};


#endif //LEETCODE_SOLUTION403_H
