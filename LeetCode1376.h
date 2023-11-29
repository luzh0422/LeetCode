//
// Created by 陆泽辉 on 2023/5/1.
//

#ifndef LEETCODE_LEETCODE1376_H
#define LEETCODE_LEETCODE1376_H

#include <vector>

using namespace std;

class LeetCode1376 {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime);

private:
    int numOfMinutes(int headId, vector<vector<int>>& tree, vector<int>& informTime);
};


#endif //LEETCODE_LEETCODE1376_H
