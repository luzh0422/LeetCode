//
// Created by 陆泽辉 on 2023/6/23.
//

#include "LeetCode2496.h"

int LeetCode2496::maximumValue(vector<string> &strs) {
    int res = 0;
    std::function<bool(string& str)> judge = [](string& str) -> bool {
        for (auto c : str) {
            if (c < '0' && c > '9') {
                return false;
            }
        }
        return true;
    };
    for (auto& str : strs) {
        if (judge(str)) {
            res = max(res, stoi(str));
        } else {
            res = max(res, (int)str.size());
        }
    }
    return res;
}
