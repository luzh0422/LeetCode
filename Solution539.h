//
// Created by luzh on 2022/1/18.
//

#ifndef LEETCODE_SOLUTION539_H
#define LEETCODE_SOLUTION539_H

#include <vector>
#include <string>

using namespace std;

class Solution539 {
public:
    int findMinDifference(vector<string>& timePoints);

private:
    vector<int> timeToMinutes(const vector<string>& timePoints);
};


#endif //LEETCODE_SOLUTION539_H
