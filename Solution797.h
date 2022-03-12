//
// Created by luzh on 2021/8/25.
//

#ifndef LEETCODE_SOLUTION797_H
#define LEETCODE_SOLUTION797_H

#include <vector>

using namespace std;

class Solution797 {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph);

private:
    void allPathsSourceTarget(vector<vector<int>>& graph, vector<int>& curr, vector<vector<int>>& ans, int target);
};


#endif //LEETCODE_SOLUTION797_H
