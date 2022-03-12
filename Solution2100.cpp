//
// Created by luzh on 2022/3/6.
//

#include "Solution2100.h"

vector<int> Solution2100::goodDaysToRobBank(vector<int> &security, int time) {
    int n = security.size();
    vector<int> left(n, 1);
    vector<int> right(n, 1);
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            left[i] = 1;
        } else {
            if (security[i] <= security[i - 1]) {
                left[i] = left[i - 1] + 1;
            } else {
                left[i] = 1;
            }
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if (i == n - 1) {
            right[i] = 1;
        } else {
            if (security[i] <= security[i + 1]) {
                right[i] = right[i + 1] + 1;
            } else {
                right[i] = 1;
            }
        }
    }
    vector<int> ret = {};
    for (int i = time; i < n - time; i++) {
        if (left[i] > time && right[i] < time) {
            ret.push_back(i);
        }
    }
    return ret;
}
