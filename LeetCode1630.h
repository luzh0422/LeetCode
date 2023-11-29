//
// Created by 陆泽辉 on 2023/3/23.
//

#ifndef LEETCODE_LEETCODE1630_H
#define LEETCODE_LEETCODE1630_H

#include <vector>

using namespace std;

class LeetCode1630 {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r);

private:
    bool checkArithmeticSubarrays(vector<int>& arr);
};


#endif //LEETCODE_LEETCODE1630_H
