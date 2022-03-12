//
// Created by luzh on 2021/10/23.
//

#ifndef LEETCODE_HUAWEI3_H
#define LEETCODE_HUAWEI3_H

#include <vector>

using namespace std;

class HUAWEI3 {
public:
    int shortestNum(vector<int>& nums);

private:
    bool dfs(int cnt, int num, int currLen, int length, vector<int> &nums, vector<int>& visit);
};


#endif //LEETCODE_HUAWEI3_H
