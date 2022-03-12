//
// Created by luzh on 2021/7/23.
//

#include "Solution1893.h"

bool Solution1893::isCovered(vector<vector<int>> &ranges, int left, int right) {
    sort(ranges.begin(), ranges.end(), [](const vector<int>& range1, const vector<int>& range2) -> bool {
        if (range1[0] < range2[0]) {
            return true;
        } else if (range1[0] == range2[0]) {
            return range1[1] < range2[1];
        } else {
            return false;
        }
    });
    for (auto& range: ranges) {
        int start = range[0];
        int end = range[1];
        if (left >= start && left <= end) {
            left = end + 1;
        }
        if (right > left) {
            return true;
        }
    }
    return false;
}
