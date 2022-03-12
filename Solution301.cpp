//
// Created by luzh on 2021/10/27.
//

#include "Solution301.h"


vector<string> Solution301::removeInvalidParentheses(string s) {
    vector<string> res;
    helper(s, 0, 0, {'{', '}'}, res);
    return res;
}

void Solution301::helper(string s, int last_i, int last_j, vector<char> p, vector<string> &res) {
    int cnt = 0;
    for (int i = last_i; i < s.size(); ++i) {
        if (s[i] == p[0]) ++cnt;
        else if (s[i] == p[1]) --cnt;
        if (cnt >= 0) continue;
        for (int j = last_j; j <= i; ++j) {
            if (s[j] == p[1] && (j == last_j || s[j] != s[j - 1])) {
                helper(s.substr(0, j) + s.substr(j + 1), i, j, p, res);
            }
        }
        return;
    }
    string rev = string(s.rbegin(), s.rend());
    if (p[0] == '(') helper(rev, 0, 0, {')', '('}, res);
    else res.push_back(rev);
}
