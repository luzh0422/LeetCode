//
// Created by 陆泽辉 on 2022/5/25.
//

#include "LeetCode467.h"
#include <vector>
#include <unordered_map>

int LeetCode467::findSubstringInWraproundString(string p) {
    vector<vector<char>> words(26, vector<char>(26, ' '));
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            words[i][j] = 'a' + (i + j) % 26;
        }
    }
    int ret = 0;
    unordered_map<char, int> uS;
    int n = p.size();
    for (int i = 0; i < n; i++) {
        int row = p[i] - 'a';
        int j = i + 1;
        for (; j < n; j++) {
            int step = (j - i) % 26;
            if (p[j] != words[row][step]) {
                break;
            }
        }
        if (uS.count(p[i])) {
            if ((j - i) > uS[p[i]]) {
                ret += j - i - uS[p[i]];
                uS[p[i]] = j - i;
            }
        } else {
            ret += j - i;
            uS.insert(unordered_map<char, int>::value_type (p[i], j - i));
        }
    }
    return ret;
}
