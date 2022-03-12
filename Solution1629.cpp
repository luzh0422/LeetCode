//
// Created by luzh on 2022/1/9.
//

#include "Solution1629.h"

char Solution1629::slowestKey(vector<int> &releaseTimes, string keysPressed) {
    char ans = keysPressed[0];
    int duration = releaseTimes[0];
    int n = releaseTimes.size();
    for (int i = 1; i < n; i++) {
        char c = keysPressed[i];
        int currTime = releaseTimes[i] - releaseTimes[i - 1];
        if (currTime > duration || currTime == duration && c > ans) {
            duration = currTime;
            ans = c;
        }
    }
    return ans;
}
