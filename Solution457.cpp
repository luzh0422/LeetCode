//
// Created by luzh on 2021/8/7.
//

#include "Solution457.h"

bool Solution457::circularArrayLoop(vector<int> &nums) {
    int size = nums.size();
    vector<int> visit(size);
    for (int i = 0; i < size; i++) {
        if (visit[i] == 0) {
            visit[i] = 1;
            int step = nums[i];
            int startStep = step;
            if (step < 0) {
                while (abs(step) < size) {
                    int curr = i + step;
                    /**
                     * 数组loop；
                     */
                    if (curr < 0) {
                        curr = curr + size;
                    }
                    visit[curr] = 1;
                    if (nums[curr] >= 0) {
                        break;
                    }
                    step += nums[curr];
                }
            } else if (step > 0) {
                while (step < size) {
                    int curr = (i + step) % size;
                    visit[curr] = 1;
                    if (nums[curr] <= 0) {
                        break;
                    }
                    step += nums[curr];
                }
            }
            if (abs(step) == size) {
                return true;
            }
        }
    }
    return false;
}
