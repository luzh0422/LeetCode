//
// Created by 陆泽辉 on 2022/10/30.
//

#include "LeetCode784.h"
#include <set>

vector<string> LeetCode784::letterCasePermutation(string s) {
    set<string> ret = {};
    backtrack(s, ret, 0);
    vector<string> result(ret.begin(), ret.end());
    return result;
}

void LeetCode784::backtrack(string &s, set<string> &ret, int curr) {
    if (curr == s.size()) {
        return;
    }
    if (s[curr] >= 'a' && s[curr] <= 'z') {
        char temp = s[curr];
        ret.emplace(s);
        backtrack(s, ret, curr + 1);
        s[curr] = 'A' + (temp - 'a');
        ret.emplace(s);
        backtrack(s, ret, curr + 1);
    } else if (s[curr] >= 'A' && s[curr] <= 'Z') {
        char temp = s[curr];
        ret.emplace(s);
        backtrack(s, ret, curr + 1);
        s[curr] = 'a' + (temp - 'A');
        ret.emplace(s);
        backtrack(s, ret, curr + 1);
    } else {
        backtrack(s, ret, curr + 1);
    }
}
