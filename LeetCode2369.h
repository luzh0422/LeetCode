//
// Created by luzehui on 2024/3/1.
//

#ifndef LEETCODE_LEETCODE2369_H
#define LEETCODE_LEETCODE2369_H

#include <vector>

using namespace std;

class LeetCode2369 {
public:
    bool validPartition(vector<int>& nums);
private:
    bool validTwo(int num1, int num2);
    bool validThree(int num1, int num2, int num3);
};


#endif //LEETCODE_LEETCODE2369_H
