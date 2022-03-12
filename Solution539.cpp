//
// Created by luzh on 2022/1/18.
//

#include "Solution539.h"

int Solution539::findMinDifference(vector<string> &timePoints) {
    auto minutes = timeToMinutes(timePoints);
    std::sort(minutes.begin(), minutes.end());
    int ans = INT_MAX;
    int n = timePoints.size();
    for (int i = 0; i < n - 1; i++) {
        ans = min(ans, min(minutes[i + 1] - minutes[i], 24 * 60 - minutes[i + 1] + minutes[i]));
    }
    ans = min(ans, min(minutes[n - 1] - minutes[0], 24 * 60 - minutes[n - 1] + minutes[0]));
    return ans;
}

vector<int> Solution539::timeToMinutes(const vector<string> &timePoints) {
    int n = timePoints.size();
    vector<int> minutes;
    minutes.reserve(n);
    for (int i = 0; i < n; i++) {
        string timePoint = timePoints[i];
        int minute = 0;
        minute = stoi(timePoint.substr(0, 2)) * 60 + stoi(timePoint.substr(3, 2));
        minutes.emplace_back(minute);
    }
    return  minutes;
}
