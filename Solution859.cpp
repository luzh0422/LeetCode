//
// Created by luzh on 2021/11/23.
//

#include "Solution859.h"
#include <vector>

bool Solution859::buddyStrings(string s, string goal) {
    if (s.size() != goal.size()) {
        return false;
    }
    int n = s.size();
    vector<int> arr(26, 0);
    vector<int> sDiffIndex;
    vector<int> goalDiffIndex;
    int diff = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] != goal[i]) {
            sDiffIndex.push_back(i);
            goalDiffIndex.push_back(i);
            diff++;
        }
        arr[s[i] - 'a']++;
        if (diff > 2) {
            return false;
        }
    }
    std::sort(arr.begin(), arr.end(), greater<int>());
    if (diff == 2 && s[sDiffIndex[0]] == goal[goalDiffIndex[1]] && s[sDiffIndex[0]] == goal[goalDiffIndex[1]] || diff == 0 && arr[0] >= 2) {
        return true;
    } else {
        return false;
    }
}
