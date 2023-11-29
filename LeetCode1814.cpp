//
// Created by 陆泽辉 on 2023/1/17.
//

#include "LeetCode1814.h"
#include <unordered_map>

int LeetCode1814::countNicePairs(vector<int> &nums) {
    int res = 0;
    const int MOD = 1e9 + 7;
    unordered_map<int, int> uM;
    for (auto num : nums) {
        int temp = reverse(num);
        temp = num - temp;
        if (uM.count(temp)) {
            res += uM[temp];
            res %= MOD;
            uM[temp]++;
        } else {
            uM.insert(unordered_map<int, int>::value_type (temp, 1));
        }
    }
    return res;
}

int LeetCode1814::reverse(int num) {
    int res = 0;
    while (num != 0) {
        int temp = num % 10;
        num /= 10;
        res = res * 10 + temp;
    }
    return res;
}
