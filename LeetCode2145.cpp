//
// Created by luzehui on 25-4-21.
//

#include "LeetCode2145.h"

int LeetCode2145::numberOfArrays(vector<int> &differences, int lower, int upper) {
    long long minVal = 0ll, maxVal = 0ll, currVal = 0ll;
    for (int difference : differences) {
        currVal = difference + currVal;
        minVal = min(minVal, currVal);
        maxVal = max(maxVal, currVal);
    }
    long long minValLower = lower - minVal, minValUpper = upper - minVal;
    long long maxValLower = lower - maxVal, maxValUpeer = upper - maxVal;
    long long valLower = max(minValLower, maxValLower);
    long long valUpper = min(minValUpper, maxValUpeer);
    return max(valUpper - valLower + 1, 0ll);
}
