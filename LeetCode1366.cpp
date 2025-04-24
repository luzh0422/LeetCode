//
// Created by luzehui on 24-12-29.
//

#include "LeetCode1366.h"
#include <unordered_map>

string LeetCode1366::rankTeams(vector<std::string> &votes) {
    string v = votes[0];
    int n = v.size();
    unordered_map<char, vector<int>> uS;
    for (string& vote : votes) {
        for (int i = 0; i < n; i++) {
            if (uS[vote[i]].empty()) {
                uS[vote[i]].resize(n, 0);
            }
            uS[vote[i]][i]++;
        }
    }
    std::sort(v.begin(), v.end(), [&](char& c1, char& c2) -> bool {
        for (int i = 0; i < n; i++) {
            if (uS[c1][i] > uS[c2][i]) {
                return true;
            } else if (uS[c1][i] < uS[c2][i]) {
                return false;
            }
        }
        return c1 < c2;
    });
    return v;
}
