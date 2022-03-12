//
// Created by luzh on 2021/5/21.
//

#ifndef LEETCODE_SOLUTION1035_H
#define LEETCODE_SOLUTION1035_H

#include <vector>

using namespace std;

class Solution1035 {
public:
    Solution1035() {}
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2);

private:
    void maxUncrossedLines(vector<int>& nums1, vector<int>& nums2, int nums1Start, int nums2Start, vector<pair<int, int>>& record, int& currAns, int& ans);
};


#endif //LEETCODE_SOLUTION1035_H
