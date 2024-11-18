//
// Created by luzehui on 2024/6/21.
//

#include "LeetCode2748.h"
#include <functional>

int LeetCode2748::countBeautifulPairs(vector<int> &nums) {
    vector<vector<int>> cache(10, vector<int>(10, -1));
    std::function<int(int, int)> gcp = [&](int num1, int num2) -> int {
        if (num1 % num2 == 0) {
            return num2;
        }
        return gcp(num2, num1 % num2);
    };
    int n = nums.size();
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int num1 = nums[i], num2 = nums[j] % 10;
            while (num1 / 10 != 0) {
                num1 /= 10;
            }
            if (num1 <  num2) {
                int temp = num2;
                num2 = num1;
                num1 = temp;
            }
            if (cache[num1][num2] != -1) {
                if (cache[num1][num2] == 1) {
                    res++;
                }
            } else {
                int temp = gcp(num1, num2);
                cache[num1][num2] = temp;
                cache[num2][num1] = temp;
                if (temp == 1) {
                    res++;
                }
            }
        }
    }
    return res;
}
