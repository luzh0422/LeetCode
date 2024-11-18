//
// Created by luzehui on 2024/7/4.
//

#include "LeetCode3099.h"
#include <functional>

using namespace std;

int LeetCode3099::sumOfTheDigitsOfHarshadNumber(int x) {
    function<int(int)> helper = [](int num) -> int {
        int res = 0;
        while (num != 0) {
            res += num % 10;
            num /= 10;
        }
        return res;
    };
    int num = helper(x);
    if (x % num == 0)
        return num;
    return -1;
}
