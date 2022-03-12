//
// Created by luzh on 2021/10/28.
//

#ifndef LEETCODE_SOLUTION869_H
#define LEETCODE_SOLUTION869_H

#include <vector>

using namespace std;

class Solution869 {
public:
    bool reorderedPowerOf2(int n);

private:
    bool backtrack(vector<int>& arr, vector<int>& visit, int curr, int index);
    bool isPowOf2(int n);
};


#endif //LEETCODE_SOLUTION869_H
