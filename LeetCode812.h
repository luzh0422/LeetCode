//
// Created by 陆泽辉 on 2022/5/15.
//

#ifndef LEETCODE_LEETCODE812_H
#define LEETCODE_LEETCODE812_H

#include <vector>

using namespace std;

class LeetCode812 {
public:
    double largestTriangleArea(vector<vector<int>>& points);

private:
    double triangleArea(vector<int>& point1, vector<int>& point2, vector<int>& point3);
};


#endif //LEETCODE_LEETCODE812_H
