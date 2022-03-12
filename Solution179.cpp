//
// Created by luzh on 2021/4/12.
//

#include "Solution179.h"

#include <stack>
#include "ListNode.h"

string Solution179::largestNumber(vector<int> &nums) {
    std::sort(nums.begin(), nums.end(), [](const int& num1, const int& num2) -> bool {
        long sx = 10, sy = 10;
        while (sx <= num1) {
            sx *= 10;
        }
        while (sy <= num2) {
            sy *= 10;
        }
        return (num1 * sy + num2 >= num2 * sx + num1);
    });
    if (nums[0] == 0) {
        return "0";
    }
    string res;
    for (int& num : nums) {
        res += to_string(num);
    }
    return res;
}
