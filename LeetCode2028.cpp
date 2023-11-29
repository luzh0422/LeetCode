//
// Created by 陆泽辉 on 2022/3/27.
//

#include "LeetCode2028.h"
#include <numeric>

vector<int> LeetCode2028::missingRolls(vector<int> &rolls, int mean, int n) {
    int m = rolls.size();
    int total = mean * (m + n);
    int mTotal = accumulate(rolls.begin(), rolls.end(), 0);
    int nTotal = total - mTotal;
    if (nTotal / n > 6 || nTotal / n == 6 && nTotal % n != 0 || nTotal < n) {
        return {};
    } else {
        int nEach = nTotal / n;
        int nDelta = nTotal % n;
        vector<int> ret = {};
        for (int i = 0; i < nDelta; i++) {
            ret.push_back(nEach + 1);
        }
        for (int i = nDelta; i < n; i++) {
            ret.push_back(nEach);
        }
        return ret;
    }
}
