//
// Created by luzh on 2021/7/3.
//

#include "Solution451.h"

#include <map>
#include <vector>

string Solution451::frequencySort(string s) {
    map<char, int> cache = {};
    for (auto& c : s) {
        if (cache.count(c)) {
            cache[c]++;
        } else {
            cache[c] = 1;
        }
    }
    vector<pair<char, int>> v(cache.begin(), cache.end());
    sort(v.begin(), v.end(), [](pair<char, int>& a, pair<char, int>& b) -> bool {
        return a.second > b.second;
    });
    string ret = "";
    for (auto& p : v) {
        int num = p.second;
        for (int i = 0; i < num; i++) {
            ret += p.first;
        }
    }
    return ret;
}
