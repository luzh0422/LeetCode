//
// Created by 陆泽辉 on 2022/5/20.
//

#include "LeetCode436.h"
#include <map>

vector<int> LeetCode436::findRightInterval(vector<vector<int>> &intervals) {
    map<int, int> starts;
    int index = 0;
    for (auto& interval: intervals) {
        int start = interval[0];
        starts.emplace(start, index);
        index++;
    }
    vector<pair<int, int>> startsCache(starts.begin(), starts.end());
    vector<int> ret;
    for (auto& interval: intervals) {
        int end = interval[1];
        int index = binarySearch(startsCache, end);
        if (startsCache[index].first < end) {
            ret.push_back(-1);
        } else {
            ret.push_back(startsCache[index].second);
        }
   }
    return ret;
}

int LeetCode436::binarySearch(vector<pair<int, int>> &starts, int end) {
    int left = 0, right = starts.size() - 1, middle = (left + right) / 2;
    while (left < right) {
        auto curr = starts[middle];
        if (curr.first == end) {
            return middle;
        } else if (curr.first > end) {
            right = middle;
        } else if (curr.first < end) {
            left = middle + 1;
        }
        middle = (left + right) / 2;
    }
    return right;
}
