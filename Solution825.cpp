//
// Created by luzh on 2021/12/27.
//

#include "Solution825.h"

/**
 * x 将向 y 发送好友请求的条件；
 * 0.5 * age[x] + 7 < age[y] <= age[x];
 * 在这个区间内的y，x可以发送好友请求；
 * 同时要排除对自己发送好友请求；
 * @param ages
 * @return
 */
int Solution825::numFriendRequests(vector<int> &ages) {
    std::sort(ages.begin(), ages.end());
    int ans = 0;
    int n = ages.size();
    int left = 0, right = 0;
    for (int i = 0; i < n; i++) {
        int curr = ages[i];
        if (curr <= 14) {
            continue;
        } else {
            while (left < n && ages[left] <= 0.5 * curr + 7) {
                left++;
            }
            while (right < n && ages[right] <= curr) {
                right++;
            }
            ans += right - left - 1;
        }
    }
    return ans;
}
