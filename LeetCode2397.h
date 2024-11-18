//
// Created by luzehui on 2024/1/4.
//

#ifndef LEETCODE_LEETCODE2397_H
#define LEETCODE_LEETCODE2397_H

#include <vector>

using namespace std;

class LeetCode2397 {
public:
    int maximumRows(vector<vector<int>>& matrix, int numSelect);

private:
    int maximumRows(vector<vector<int>>& matrix, int numSelect, int start);
};


#endif //LEETCODE_LEETCODE2397_H
