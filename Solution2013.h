//
// Created by luzh on 2022/1/26.
//

#ifndef LEETCODE_SOLUTION2013_H
#define LEETCODE_SOLUTION2013_H

#include <vector>
#include <unordered_map>

using namespace std;

class Solution2013 {
public:
    Solution2013();

    void add(vector<int> point);

    int count(vector<int> point);

private:
    unordered_map<int, vector<pair<int, int>>> columns;
    unordered_map<int, vector<pair<int, int>>> rows;
};


#endif //LEETCODE_SOLUTION2013_H
