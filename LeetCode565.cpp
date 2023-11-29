//
// Created by 陆泽辉 on 2022/7/17.
//

#include "LeetCode565.h"

int LeetCode565::arrayNesting(vector<int> &nums) {
    int n = nums.size(), ret = 0;
    vector<int> visit(n, 0);
    for (int i = 0; i < n; i++) {
        visit[i] = 1;
        int next = nums[i];
        int temp = 1;
        while (visit[next] != 1) {
            visit[next] = 1;
            temp++;
            next = nums[next];
        }
        ret = max(ret, temp);
    }
    return ret;
}
