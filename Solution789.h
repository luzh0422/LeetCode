//
// Created by luzh on 2021/8/22.
//

#ifndef LEETCODE_SOLUTION789_H
#define LEETCODE_SOLUTION789_H

#include <vector>

using namespace std;

class Solution789 {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target);

private:
    int manhattanDistance(vector<int> point1, vector<int> point2);
};


#endif //LEETCODE_SOLUTION789_H
