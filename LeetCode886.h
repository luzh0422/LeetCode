//
// Created by 陆泽辉 on 2022/10/16.
//

#ifndef LEETCODE_LEETCODE886_H
#define LEETCODE_LEETCODE886_H

#include <vector>

using namespace std;

class LeetCode886 {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes);

private:
    bool dfs(int index, int newColor, vector<int>& colors, vector<vector<int>>& graph);
};


#endif //LEETCODE_LEETCODE886_H
