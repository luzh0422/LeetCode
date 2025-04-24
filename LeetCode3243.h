//
// Created by luzehui on 2024/11/19.
//

#ifndef LEETCODE_LEETCODE3243_H
#define LEETCODE_LEETCODE3243_H

#include <vector>

using namespace std;

class LeetCode3243 {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries);

private:
    void dijkstra(vector<vector<int>>& graph, int* distance, int* edge);
};


#endif //LEETCODE_LEETCODE3243_H
