//
// Created by luzehui on 2024/10/2.
//

#ifndef LEETCODE_LEETCODE1870_H
#define LEETCODE_LEETCODE1870_H

#include <vector>

using namespace std;

class LeetCode1870 {
public:
    int minSpeedOnTime(vector<int>& dist, double hour);

private:
    double getTotalTime(vector<int>& dist, int speed);
};


#endif //LEETCODE_LEETCODE1870_H
