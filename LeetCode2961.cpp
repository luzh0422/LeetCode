//
// Created by luzehui on 2024/7/31.
//

#include "LeetCode2961.h"

int LeetCode2961::QuickPow(int a, int b, int c) {
    int res = 1;
    while (b) {
        if ((b & 1) == 1) {
            // res = 1 或者 res = a；从而处理b单双数的问题；
            res = res * a % c;
        }
        a = a * a % c;
        b >>= 1;
    }
    return res;
}

vector<int> LeetCode2961::getGoodIndices(vector<vector<int>> &variables, int target) {
    vector<int> ans;
    int index = 0;
    for (auto& variable : variables) {
        if (QuickPow(QuickPow(variable[0], variable[1], 10), variable[2], variable[3]) == target) {
            ans.push_back(index);
        }
        index++;
    }
    return ans;
}
