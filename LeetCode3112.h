//
// Created by luzehui on 2024/7/18.
//

#ifndef LEETCODE_LEETCODE3112_H
#define LEETCODE_LEETCODE3112_H

#include <vector>

using namespace std;

class LeetCode3112 {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear);

private:
    void dijkstra(int n, vector<vector<int>>& edges, vector<int>& distances);
};


#endif //LEETCODE_LEETCODE3112_H
