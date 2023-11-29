//
// Created by 陆泽辉 on 2022/9/14.
//

#include "LeetCode1619.h"
#include <numeric>

double LeetCode1619::trimMean(vector<int> &arr) {
    std::sort(arr.begin(), arr.end());
    auto end = arr.end();
    auto begin = arr.begin();
    int n = arr.size();
    int deleteNum = n * 0.05;
    advance(end, -deleteNum);
    advance(begin, deleteNum);
    double ret = static_cast<double>(accumulate(begin, end, 0)) / (n - 2 * deleteNum);
    return ret;
}
