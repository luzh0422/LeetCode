//
// Created by luzh on 2021/8/29.
//

#ifndef LEETCODE_SOLUTION1588_H
#define LEETCODE_SOLUTION1588_H

#include <vector>

using namespace std;

class Solution1588 {
public:
    int sumOddLengthSubarrays(vector<int>& arr);

private:
    int sumOddLengthSubarrays(vector<int>& arr, int start, int length);
};


#endif //LEETCODE_SOLUTION1588_H
