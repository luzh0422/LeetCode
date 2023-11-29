//
// Created by 陆泽辉 on 2023/8/21.
//

#include "LeetCode2337.h"
#include <vector>

bool LeetCode2337::canChange(string start, string target) {
    vector<pair<char, int>> starts;
    vector<pair<char, int>> targets;
    for (int i = 0; i < start.size(); i++) {
        if (start[i] != '_')
            starts.emplace_back(start[i], i);
    }
    for (int i = 0; i < target.size(); i++) {
        if (target[i] != '_')
            targets.emplace_back(target[i], i);
    }
    if (starts.size() != targets.size()) {
        return false;
    }
    int n = starts.size();
    for (int i = 0; i < n; i++) {
        if (starts[i].first != targets[i].first) {
            return false;
        }
        if (starts[i].first == 'L' && starts[i].second < targets[i].second) {
            return false;
        }
        if (starts[i].first == 'R' && starts[i].second > targets[i].second) {
            return false;
        }
    }
    return true;
}
