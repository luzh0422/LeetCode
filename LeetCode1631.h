//
// Created by luzehui on 2023/12/11.
//

#ifndef LEETCODE_LEETCODE1631_H
#define LEETCODE_LEETCODE1631_H

#include <vector>

using namespace std;

class LeetCode1631 {
public:
    int minimumEffortPath(vector<vector<int>>& heights);

private:
    bool dfs(vector<vector<int>>& heights, vector<vector<int>>& visits, pair<int, int> curr, pair<int, int> last, int target);
};


#endif //LEETCODE_LEETCODE1631_H
