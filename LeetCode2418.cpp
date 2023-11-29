//
// Created by 陆泽辉 on 2023/4/25.
//

#include "LeetCode2418.h"

vector<string> LeetCode2418::sortPeople(vector<string> &names, vector<int> &heights) {
    vector<pair<string, int>> namesAndHeights;
    int n = names.size();
    for (int i = 0; i < n; i++) {
        namesAndHeights.emplace_back(names[i], heights[i]);
    }
    std::sort(namesAndHeights.begin(), namesAndHeights.end(), [](pair<string, int>& nameAndHeight1, pair<string, int>& nameAndHeight2) -> bool {
        return nameAndHeight1.second > nameAndHeight2.second;
    });
    for (int i = 0; i < n; i++) {
        names[i] = namesAndHeights[i].first;
    }
    return names;
}
