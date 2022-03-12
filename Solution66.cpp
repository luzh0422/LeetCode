//
// Created by luzh on 2021/10/21.
//

#include "Solution66.h"

vector<int> Solution66::plusOne(vector<int> &digits) {
    int step = 1;
    int n = digits.size() - 1;
    for (int i = n; i >= 0; i--) {
        if (step == 0) {
            break;
        }
        int &curr = digits[i];
        curr += step;
        step = curr / 10;
        curr = curr % 10;
    }
    if (step != 0) {
        digits.insert(digits.begin(), 1);
    }
    return digits;
}
