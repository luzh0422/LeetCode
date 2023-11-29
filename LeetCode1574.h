//
// Created by 陆泽辉 on 2023/3/25.
//

#ifndef LEETCODE_LEETCODE1574_H
#define LEETCODE_LEETCODE1574_H

#include <vector>

using namespace std;

class LeetCode1574 {
public:
    int findLengthOfShortestSubarray(vector<int>& arr);

private:
    int findLengthOfShortestSubarray(vector<int>& arr, int prefixLeft, int prefixRight, int suffixLeft, int suffixRight, vector<vector<int>>& cahce);
};


#endif //LEETCODE_LEETCODE1574_H
