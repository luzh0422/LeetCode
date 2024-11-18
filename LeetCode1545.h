//
// Created by luzehui on 2024/5/19.
//

#ifndef LEETCODE_LEETCODE1545_H
#define LEETCODE_LEETCODE1545_H

#include <vector>
#include <queue>

using namespace std;

class LeetCode1545 {
public:
    int getWinner(vector<int>& arr, int k);

private:
    int getWinner(queue<int>& arr, int k, int curr, int currStep);
};


#endif //LEETCODE_LEETCODE1545_H
