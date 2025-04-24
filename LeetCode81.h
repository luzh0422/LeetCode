//
// Created by luzehui on 25-2-1.
//

#ifndef LEETCODE_LEETCODE81_H
#define LEETCODE_LEETCODE81_H

#include <vector>

using namespace std;

class LeetCode81 {
public:
    bool search(vector<int>& nums, int target);

private:
    bool binarySearch(vector<int>& nums, int left, int right, int target);
};


#endif //LEETCODE_LEETCODE81_H
