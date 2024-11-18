//
// Created by luzehui on 2024/9/14.
//

#include "LeetCode2390.h"

string LeetCode2390::removeStars(std::string s) {
    string res = "";
    for (auto c : s) {
        if (c == '*') {
            res.pop_back();
        } else {
            res.push_back(c);
        }
    }
    return res;
}
