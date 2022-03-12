//
// Created by luzh on 2021/11/22.
//

#ifndef LEETCODE_SOLUTION384_H
#define LEETCODE_SOLUTION384_H

#include <vector>

using namespace std;

class Solution384 {
public:
    Solution384(vector<int>& nums);
    vector<int> reset();
    vector<int> shuffle();

private:
    vector<int> origin;
};


#endif //LEETCODE_SOLUTION384_H
