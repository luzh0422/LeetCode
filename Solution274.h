//
// Created by luzh on 2021/7/11.
//

#ifndef LEETCODE_SOLUTION274_H
#define LEETCODE_SOLUTION274_H

#include <vector>

using namespace std;

class Solution274 {
public:
    int hIndex(vector<int>& citations);

private:
    int greaterThanNum(vector<int>& citations, int num);
};


#endif //LEETCODE_SOLUTION274_H
