//
// Created by luzh on 2021/11/16.
//

#include "Solution391.h"
#include <set>

bool Solution391::isRectangleCover(vector<vector<int>> &rectangles) {
    int left = INT_MAX;
    int right = INT_MIN;
    int top = INT_MIN;
    int bottom = INT_MAX;
    int sumArea = 0;
    set<pair<int, int>> points = {};
    for (vector<int>& rectangle: rectangles) {
        int currLeft = rectangle[0];
        int currRight = rectangle[2];
        int currTop = rectangle[3];
        int currBottom = rectangle[1];
        left = min(left, currLeft);
        right = max(right, currRight);
        top = max(top, currTop);
        bottom = min(bottom, currBottom);
        sumArea += (currRight - currLeft) * (currTop - currBottom);
        if (points.count({currLeft, currTop})) {
            points.erase({currLeft, currTop});
        } else {
            points.insert({currLeft, currTop});
        }
        if (points.count({currRight, currTop})) {
            points.erase({currRight, currTop});
        } else {
            points.insert({currRight, currTop});
        }
        if (points.count({currLeft, currBottom})) {
            points.erase({currLeft, currBottom});
        } else {
            points.insert({currLeft, currBottom});
        }
        if (points.count({currRight, currBottom})) {
            points.erase({currRight, currBottom});
        } else {
            points.insert({currRight, currBottom});
        }
    }
    int area = (right - left) * (top - bottom);
    if (area == sumArea && points.size() == 4 && points.count({left, top}) && points.count({left, bottom}) && points.count({right, top}) && points.count({right, bottom})) {
        return true;
    }
    return false;
}
