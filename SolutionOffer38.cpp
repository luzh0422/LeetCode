//
// Created by luzh on 2021/6/22.
//

#include "SolutionOffer38.h"

vector<string> SolutionOffer38::permutation(string s) {
    vector<string> ans = {};
    int curr = 0;
    unordered_map<string, int> cache = {};
    string currString = "";
    permutation(s, currString, ans, curr, cache);
    return ans;
}

void SolutionOffer38::permutation(string s, string& currString, vector<string> &ans, int curr, unordered_map<string, int> &cache) {
    if (__builtin_popcount(curr) == s.size()) {
        if (!cache.count(currString)) {
            ans.push_back(currString);
            cache[currString] = 1;
        }
        return;
    }
    int sSize = s.size();
    for (int i = 0; i < sSize; i++) {
        if (((1 << i) & curr) == 0) {
            curr |= (1 << i);
            currString += s[i];
            permutation(s, currString, ans, curr, cache);
            curr ^= (1 << i);
            currString.resize(currString.size() - 1);
        }
    }
    return;
}
