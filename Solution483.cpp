//
// Created by luzh on 2021/11/28.
//

#include "Solution483.h"

vector<int> Solution483::findAnagrams(string s, string p) {
    int pSize = p.size();
    int sSize = s.size();
    if (sSize < pSize) {
        return {};
    }
    int pNum = sToI(p);
    sortString(p);
    vector<int> ans = {};
    for (int i = 0; i < sSize - pSize + 1; i++) {
        char c = s[i];
        int index = 1 << (c - 'a');
        if ((index & pNum) != 0) {
            string subStr = s.substr(i, pSize);
            sortString(subStr);
            if (subStr == p) {
                ans.push_back(i);
            }
        }
    }
    return ans;
}

int Solution483::sToI(string s) {
    int num = 0;
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        num |= (1 << (c - 'a'));
    }
    return num;
}

void Solution483::sortString(string &s) {
    std::sort(s.begin(), s.end(), [](char c1, char c2) -> bool {
        return c1 < c2;
    });
}
