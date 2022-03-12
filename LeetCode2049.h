//
// Created by luzh on 2022/3/11.
//

#ifndef LEETCODE_LEETCODE2049_H
#define LEETCODE_LEETCODE2049_H

#include <vector>

using namespace std;

class LeetCode2049 {
public:
    int countHighestScoreNodes(vector<int>& parents);

private:
    int getChildVal(vector<vector<int>>& graph, int root, vector<vector<int>>& childrenVal);
};


#endif //LEETCODE_LEETCODE2049_H
