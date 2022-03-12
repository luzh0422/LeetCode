//
// Created by luzh on 2021/8/31.
//

#include "Solution419.h"

vector<int> Solution419::corpFlightBookings(vector<vector<int>> &bookings, int n) {
    vector<int> ans(n);
    for (auto& booking : bookings) {
        int start = booking[0] - 1;
        int end = booking[1] - 1;
        int num = booking[2];
        for (int i = start; i <= end; i++) {
            ans[i] += num;
        }
    }
    return ans;
}
