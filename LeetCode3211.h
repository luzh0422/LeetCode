//
// Created by luzehui on 2024/10/29.
//

#ifndef LEETCODE_LEETCODE3211_H
#define LEETCODE_LEETCODE3211_H

#include <string>
#include <vector>

using namespace std;

class LeetCode3211 {
public:
    vector<string> validStrings(int n);

private:
    void dfs(int n, string&& s, bool preIsZero, vector<string>& res);
};


#endif //LEETCODE_LEETCODE3211_H
