//
// Created by luzehui on 2024/10/27.
//

#ifndef LEETCODE_LEETCODE684_H
#define LEETCODE_LEETCODE684_H

#include <vector>

using namespace std;

namespace {
class UnionFind {
public:
    UnionFind(int n);

    int find(int num);

    void unionSet(int num1, int num2);

private:
    vector<int> parents;
    vector<int> ranks;
};
}

class LeetCode684 {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges);
};


#endif //LEETCODE_LEETCODE684_H
