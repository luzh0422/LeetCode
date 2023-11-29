//
// Created by 陆泽辉 on 2023/5/4.
//

#ifndef LEETCODE_LEETCODE970_H
#define LEETCODE_LEETCODE970_H

#include <vector>
#include <unordered_set>

using namespace std;

class LeetCode970 {
public:
    vector<int> powerfulIntegers(int x, int y, int bound);
private:
    void powerfulIntergers(int currX, int currY, int x, int y, int bound, unordered_set<int>& cache);
};


#endif //LEETCODE_LEETCODE970_H
