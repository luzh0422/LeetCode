//
// Created by 陆泽辉 on 2023/1/11.
//

#include "LeetCode2283.h"
#include <vector>

bool LeetCode2283::digitCount(string num) {
    vector<int> target(10, 0);
    vector<int> curr(10, 0);
    int n = num.size();
    for (int i = 0; i < n; i++) {
        int temp = num[i] - '0';
        target[i] = temp;
        curr[temp]++;
    }
    for (int i = 0; i < 10; i++) {
        if (target[i] != curr[i]) {
            return false;
        }
    }
    return true;
}
