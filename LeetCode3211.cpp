//
// Created by luzehui on 2024/10/29.
//

#include "LeetCode3211.h"

vector<string> LeetCode3211::validStrings(int n) {
    vector<string> res;
    dfs(n, "", false, res);
    return res;
}

void LeetCode3211::dfs(int n, std::string &&s, bool preIsZero, vector<std::string> &res) {
    if (n == 0) {
        res.push_back(s);
        return;
    }
    dfs(n - 1, s + "1", false, res);
    if (!preIsZero) {
        dfs(n - 1, s + "0", true, res);
    }
    return;
}
