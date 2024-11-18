//
// Created by luzehui on 2024/7/31.
//

#ifndef LEETCODE_LEETCODE2961_H
#define LEETCODE_LEETCODE2961_H

#include <vector>

using namespace std;

class LeetCode2961 {
public:
    vector<int> getGoodIndices(vector<vector<int>>& variables, int target);

private:
    int QuickPow(int a, int b, int c);
};


#endif //LEETCODE_LEETCODE2961_H
