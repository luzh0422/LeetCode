//
// Created by 陆泽辉 on 2023/8/27.
//

#include "LeetCode56.h"

vector<vector<int>> LeetCode56::merge(vector<vector<int>> &intervals) {
    std::sort(intervals.begin(), intervals.end(), [](vector<int>& interval1, vector<int>& interval2) -> bool {
        if (interval1[0] < interval2[0] || interval1[0] == interval2[0] && interval1[1] < interval2[1])
            return true;
        return false;
    });
    int n = intervals.size();
    vector<vector<int>> res;
    int index = 0;
    while (index < n) {
        int left = intervals[index][0];
        int right = intervals[index][1];
        int temp = index++;
        while (temp < n && intervals[temp][0] <= right) {
            right = max(intervals[temp][1], right);
            temp++;
        }
        res.push_back({left, right});
        index = temp;
    }
    return res;
}
