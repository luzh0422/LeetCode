//
// Created by luzehui on 24-12-20.
//

#include "LeetCode3138.h"
#include <unordered_map>

int LeetCode3138::minAnagramLength(std::string s) {
    int n = s.size();
    for (int i = 1; i < n; i++) {
        if (n % i == 0) {
            if (check(s, i)) {
                return i;
            }
        }
    }
    return n;
}

bool LeetCode3138::check(std::string s, int n) {
    unordered_map<int, int> uM;
    int i = 0;
    while (i < n) {
        uM[s[i] - 'a'] += 1;
        i++;
    }
    while (i < s.size()) {
        int index = 0;
        auto uMt = uM;
        while (index < n) {
            uMt[s[i] - 'a'] -= 1;
            index++;
            i++;
        }
        for (auto iter = uMt.begin(); iter != uMt.end(); iter++) {
            if (iter->second != 0) {
                return false;
            }
        }
    }
    return true;
}
