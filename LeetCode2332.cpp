//
// Created by luzehui on 2024/9/18.
//

#include "LeetCode2332.h"

int LeetCode2332::latestTimeCatchTheBus(vector<int> &buses, vector<int> &passengers, int capacity) {
    sort(buses.begin(), buses.end());
    sort(passengers.begin(), passengers.end());
    int pos = 0;
    int space = 0;
    for (int arrive : buses) {
        space = capacity;
        // 模拟乘客上车；
        while (space > 0 && pos < passengers.size() && passengers[pos] <= arrive) {
            space--;
            pos++;
        }
    }
    pos--;
    // 如果最后一辆车，还有空间，直接上最后一辆车，且不能与其他乘客时间相同；
    // 如果最后一辆车，没有空间，则要比最后一辆车的最后一个人提前，且不能与其他乘客时间相同；
    int lastCatchTime = space > 0 ? buses.back() : passengers[pos];
    while (pos >= 0 && passengers[pos] == lastCatchTime) {
        pos--;
        lastCatchTime--;
    }
    return lastCatchTime;
}
