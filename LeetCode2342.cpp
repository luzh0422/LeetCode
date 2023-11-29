//
// Created by luzehui on 2023/11/19.
//

#include "LeetCode2342.h"
#include <unordered_map>

int LeetCode2342::maximumSum(vector<int> &nums) {
    auto helper = [=](int num) -> int {
        int res = 0;
        while (num != 0) {
            res += (num % 10);
            num /= 10;
        }
        return res;
    };
    unordered_map<int, int> uM;
    int res = -1;
    for (auto num : nums) {
        int temp = helper(num);
        if (uM.count(temp)) {
            res = max(res, uM[temp] + num);
            if (num > uM[temp]) {
                uM[temp] = num;
            }
        } else {
            uM.insert(unordered_map<int, int>::value_type(temp, num));
        }
    }
    return res;
}
