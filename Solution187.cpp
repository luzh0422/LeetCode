//
// Created by luzh on 2021/10/8.
//

#include "Solution187.h"

#include <unordered_map>

vector<string> Solution187::findRepeatedDnaSequences(string s) {
    const int L = 10;
    int n = s.size();
    vector<string> ans = {};
    unordered_map<string, int> unorderedMap;
    for (int i = 0; i <= n - L; i++) {
        string sub = s.substr(i, L);
        if (unorderedMap.count(sub)) {
            if (unorderedMap[sub] == 1) {
                ans.push_back(sub);
            }
            unorderedMap[sub]++;
        } else {
            unorderedMap[sub] = 1;
        }
    }
    return ans;
}
