//
// Created by 陆泽辉 on 2022/5/20.
//

#ifndef LEETCODE_LEETCODE436_H
#define LEETCODE_LEETCODE436_H

#include <vector>
#include <map>

using namespace std;

class LeetCode436 {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals);

private:
    int binarySearch(vector<pair<int, int>>& starts, int end);
};


#endif //LEETCODE_LEETCODE436_H
