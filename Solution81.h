//
// Created by luzh on 2021/4/7.
//

#ifndef LEETCODE_SOLUTION81_H
#define LEETCODE_SOLUTION81_H

#include <vector>

using namespace std;

class Solution81 {
public:
    Solution81() {}
    bool search(vector<int>& nums, int target);

private:
    bool binarySearch(vector<int>& nums, int left, int right, int target);
};


#endif //LEETCODE_SOLUTION81_H
