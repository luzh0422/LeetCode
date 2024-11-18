//
// Created by luzehui on 2024/10/5.
//

#include "LeetCode2187.h"
#include <functional>

long long LeetCode2187::minimumTime(vector<int> &time, int totalTrips) {
    long long minTime = *min_element(time.begin(), time.end());
    long long left = 1ll, right = totalTrips * minTime;
    function<long long(long long)> getTotalTrip = [&](long long t1) -> long long {
        long long res = 0ll;
        for (auto t : time) {
            res += t1 / t;
        }
        return res;
    };
    while (left < right) {
        long long middle = (left + right) / 2;
        int trip = getTotalTrip(middle);
        if (trip < totalTrips) {
            left = middle + 1;
        } else {
            right = middle;
        }
    }
    return left;
}
