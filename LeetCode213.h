//
// Created by 陆泽辉 on 2023/9/17.
//

#ifndef LEETCODE_LEETCODE213_H
#define LEETCODE_LEETCODE213_H

#include <vector>

using namespace std;

class LeetCode213 {
public:
    int rob(vector<int>& nums);

private:
    int rob(vector<int>& nums, int start, int end);
};


#endif //LEETCODE_LEETCODE213_H
