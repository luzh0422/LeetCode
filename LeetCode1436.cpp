//
// Created by luzehui on 2024/10/8.
//

#include "LeetCode1436.h"
#include <unordered_set>

string LeetCode1436::destCity(vector<vector<std::string>> &paths) {
    unordered_set<string> uS;
    for (auto& path : paths) {
        uS.insert(path[0]);
    }
    for (auto& path : paths) {
        if (!uS.count(path[1])) {
            return path[1];
        }
    }
    return "";
}
