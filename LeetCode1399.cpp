//
// Created by luzehui on 25-4-23.
//

#include "LeetCode1399.h"
#include <functional>
#include <unordered_map>

int LeetCode1399::countLargestGroup(int n) {
    std::function<int(int)> getNum = [](int num) -> int {
        int res = 0;
        while (num != 0) {
            res += num % 10;
            num /= 10;
        }
        return res;
    };
    std::unordered_map<int, int> cache;
    int maxCount = 0, res = 0;
    for (int i = 1; i <= n; i++) {
        int count = getNum(i);
        cache[count]++;
        if (cache[count] > maxCount) {
            res = 1;
            maxCount = cache[count];
        } else if (cache[count] == maxCount) {
            res++;
        }
    }
    return res;
}
