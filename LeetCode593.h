//
// Created by 陆泽辉 on 2022/7/29.
//

#ifndef LEETCODE_LEETCODE593_H
#define LEETCODE_LEETCODE593_H

#include <vector>

using namespace std;

class LeetCode593 {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4);

private:
    int distance(vector<int>&p1, vector<int>& p2);
    int dot(vector<int>& vec1, vector<int>& vec2);
};


#endif //LEETCODE_LEETCODE593_H
