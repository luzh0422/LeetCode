//
// Created by luzh on 2021/7/18.
//

#include "SolutionMian10_02.h"
#include <unordered_map>

vector<vector<string>> SolutionMian10_02::groupAnagrams(vector<string> &strs) {
    unordered_map<string, vector<string>> uM;
    for (auto& str: strs) {
        string key = str;
        sort(key.begin(), key.end());
        uM[key].emplace_back(str);
    }
    vector<vector<string>> ans = {};
    for (auto it = uM.begin(); it != uM.end(); it++) {
        ans.emplace_back(it->second);
    }
    return ans;
}
