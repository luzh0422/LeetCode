//
// Created by luzehui on 2024/5/6.
//

#include "LeetCode1491.h"

#include <algorithm>
#include <numeric>

double LeetCode1491::average(vector<int> &salary) {
    auto maxIter = max_element(salary.begin(), salary.end());
    salary.erase(maxIter);
    auto minIter = min_element(salary.begin(), salary.end());
    salary.erase(minIter);
    auto total = std::accumulate(salary.begin(), salary.end(), 0.0);
    return double(total / salary.size());
}
