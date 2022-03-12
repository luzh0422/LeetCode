//
// Created by luzh on 2021/5/15.
//

#include "Solution13.h"
#include <unordered_map>

int Solution13::romanToInt(string s) {
    unordered_map<char, int> cache = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };
    int ans = 0, size = s.size();
    if (size == 0) {
        return ans;
    }
    for (int i = 0; i < size - 1; i++) {
        if (cache[s[i]] < cache[s[i + 1]]) {
            ans -= cache[s[i]];
        } else {
            ans += cache[s[i]];
        }
    }
    ans += cache[s[size - 1]];
    return ans;
}
