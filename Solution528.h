//
// Created by luzh on 2021/8/30.
//

#ifndef LEETCODE_SOLUTION528_H
#define LEETCODE_SOLUTION528_H

#include <vector>

using namespace std;

class Solution528 {
public:
    Solution528(vector<int>& w);
    int pickIndex();

private:
    vector<int> pre;
};


#endif //LEETCODE_SOLUTION528_H
