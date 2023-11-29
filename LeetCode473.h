//
// Created by 陆泽辉 on 2022/6/1.
//

#ifndef LEETCODE_LEETCODE473_H
#define LEETCODE_LEETCODE473_H

#include <vector>

using namespace std;

class LeetCode473 {
public:
    bool makesquare(vector<int>& matchsticks);

private:
    bool makesquare(int index, vector<int> &matchsticks, vector<int> &edges, int len);
};


#endif //LEETCODE_LEETCODE473_H
