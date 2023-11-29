//
// Created by 陆泽辉 on 2023/8/28.
//

#include "LeetCode57.h"

class cmp1 {
public:
    bool operator()(const vector<int>& interval1, const vector<int>& interval2) {
        return interval2[1] >= interval1[0];
    }
};

class cmp2 {
public:
    bool operator()(const vector<int>& interval1, const vector<int>& interval2) {
        return interval2[0] > interval1[1];
    }
};

vector<vector<int>> LeetCode57::insert(vector<vector<int>> &intervals, vector<int> &newInterval) {
    auto start = upper_bound(intervals.begin(), intervals.end(), newInterval, cmp1());
    if (start == intervals.end()) {
        intervals.push_back(newInterval);
        return intervals;
    }
    auto end = upper_bound(intervals.begin(), intervals.end(), newInterval, cmp2());
    vector<vector<int>> res;
    auto it = intervals.begin();
    while (it != start) {
        res.push_back(*it);
        it++;
    }
    if (start == end) {
        res.push_back(newInterval);
    } else {
        int left = min((*start)[0], newInterval[0]);
        int right = max((*start)[1], newInterval[1]);
        while (it != end) {
            right = max((*it)[1], newInterval[1]);
            it++;
        }
        res.push_back({left, right});
    }
    while (it != intervals.end()) {
        res.push_back(*it);
        it++;
    }
    return res;
}
