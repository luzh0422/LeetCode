//
// Created by luzehui on 25-2-18.
//

#ifndef LEETCODE_LEETCODE2080_H
#define LEETCODE_LEETCODE2080_H

#include <vector>
#include <unordered_map>

using namespace std;

class RangeFreqQuery {
public:
    RangeFreqQuery(vector<int>& arr);

    int query(int left, int right, int value);

private:
    unordered_map<int, vector<int>> record;
    int greaterOrEqualNum(vector<int>& arr, int value);
    int lessOrEqualNum(vector<int>& arr, int value);
};

#endif //LEETCODE_LEETCODE2080_H
