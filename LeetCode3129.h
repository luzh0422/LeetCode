//
// Created by luzehui on 2024/8/6.
//

#ifndef LEETCODE_LEETCODE3129_H
#define LEETCODE_LEETCODE3129_H

#include <vector>

using namespace std;

class LeetCode3129 {
public:
    int numberOfStableArrays(int zero, int one, int limit);

private:
    int dfs(int i, int j, int k, int limit, vector<vector<vector<int>>>& memo);
};


#endif //LEETCODE_LEETCODE3129_H
