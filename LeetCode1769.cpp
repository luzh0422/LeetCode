//
// Created by 陆泽辉 on 2022/12/2.
//

#include "LeetCode1769.h"

vector<int> LeetCode1769::minOperations(string boxes) {
    int n = boxes.size();
    vector<int> ret(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ret[i] += abs(i - j) * (boxes[j] - '0');
        }
    }
    return ret;
}
