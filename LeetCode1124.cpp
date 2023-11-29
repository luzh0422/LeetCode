//
// Created by 陆泽辉 on 2023/2/14.
//

#include "LeetCode1124.h"
#include <unordered_map>

int LeetCode1124::longestWPI(vector<int> &hours) {
    unordered_map<int, int> uM = {};
    int sum = 0;
    int res = 0;
    int n = hours.size();
    for (int i = 0; i < n; i++) {
        if (hours[i] > 8) {
            sum += 1;
        } else {
            sum -= 1;
        }
        if (sum > 0) {
            res = max(res, i + 1);
        } else {
            if (uM.count(sum - 1)) {
                res = max(res, i - uM[sum - 1]);
            }
            if (!uM.count(sum)) {
                uM.insert(unordered_map<int, int>::value_type (sum, i));
            }
        }
    }
    return res;
}
