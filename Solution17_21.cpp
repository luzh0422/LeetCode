//
// Created by luzh on 2021/4/2.
//

#include "Solution17_21.h"

int Solution17_21::trap(vector<int> &height) {
    int size = height.size();
    if (size == 0) {
        return 0;
    }
    vector<int> leftMax(size); // 用于代表index左边的最大值；
    vector<int> rightMax(size); // 用于代表index右边的最大值；
    leftMax[0] = height[0]; // 初始化状态，index = 0时，左边最大的值就是自己；
    for (int i = 1; i < size; i++) {
        leftMax[i] = max(height[i], leftMax[i - 1]); // 动态规划，左边最大值可能是从左边找，也可能是本身；
    }
    rightMax[size - 1] = height[size - 1];
    for (int i = size - 1; i >= 0; i--) {
        rightMax[i] = max(height[i], rightMax[i + 1]);
    }
    int ans = 0;
    for (int i = 0; i < size; i++) {
        ans += min(leftMax[i], rightMax[i]) - height[i];
    }
    return ans;
}
