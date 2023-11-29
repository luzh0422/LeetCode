//
// Created by 陆泽辉 on 2022/7/3.
//

#include "LeetCode556.h"

#include <vector>

using namespace std;

int LeetCode556::nextGreaterElement(int n) {
    vector<int> nums;
    int last = n % 10;
    n /= 10;
    nums.emplace_back(last);
    while (n != 0) {
        int curr = n % 10;
        n /= 10;
        nums.emplace_back(curr);
        if (curr < last) {
            int size = nums.size();
            for (int j = 0; j < size - 1; j++) {
                if (nums[j] > curr) {
                    int temp = nums[size - 1];
                    nums[size - 1] = nums[j];
                    nums[j] = temp;
                    break;
                }
            }
            std::sort(nums.begin(), nums.end() - 1, greater<int>());
            long long ret = n;
            for (int j = size - 1; j >= 0; j--) {
                ret = ret * 10 + nums[j];
            }
            if (ret > INT_MAX) {
                return -1;
            }
            return ret;
        } else {
            last = curr;
        }
    }
    return -1;
}
