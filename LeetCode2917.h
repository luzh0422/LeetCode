//
// Created by luzehui on 2024/3/6.
//

#ifndef LEETCODE_LEETCODE2917_H
#define LEETCODE_LEETCODE2917_H

#include <vector>

using namespace std;

class LeetCode2917 {
public:
    int findKOr(vector<int>& nums, int k);

private:
    void countBit(int num, vector<int>& bits);
};


#endif //LEETCODE_LEETCODE2917_H
