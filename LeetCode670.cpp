//
// Created by 陆泽辉 on 2022/9/13.
//

#include "LeetCode670.h"
#include <vector>

using namespace std;

int LeetCode670::maximumSwap(int num) {
    vector<int> nums;
    while (num != 0) {
        int curr = num % 10;
        nums.insert(nums.begin(), curr);
        num /= 10;
    }
    vector<int> numsCopy(nums.begin(), nums.end());
    std::sort(numsCopy.begin(), numsCopy.end(), greater<int>());
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        if (nums[i] != numsCopy[i]) {
            for (int j = n - 1; j > i; j--) {
                if (nums[j] == numsCopy[i]) {
                    int temp = nums[j];
                    nums[j] = nums[i];
                    nums[i] = temp;
                }
            }
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        num = num * 10 + nums[i];
    }
    return num;
}
