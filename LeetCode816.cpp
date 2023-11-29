//
// Created by 陆泽辉 on 2022/11/8.
//

#include "LeetCode816.h"

vector<string> LeetCode816::ambiguousCoordinates(string s) {
    int n = s.size();
    vector<string> ret;
    for (int i = 2; i < n - 1; i++) {
        string s1 = s.substr(1, i - 1);
        string s2 = s.substr(i, n - i - 1);
        auto str1 = ambiguousCoordinatesHelper(s1, s1.size());
        auto str2 = ambiguousCoordinatesHelper(s2, s2.size());
        for (int j = 0; j < str1.size(); j++) {
            for (int k = 0; k < str2.size(); k++) {
                ret.emplace_back("(" + str1[j] + ", " + str2[k] + ")");
            }
        }
    }
    return ret;
}

vector<string> LeetCode816::ambiguousCoordinatesHelper(string s, int dotIndex) {
    int n = s.size();
    if (dotIndex == 0) {
        return {};
    }
    vector<string> ret = {};
    string sCopy = "";
    for (int i = 0; i < n; i++) {
        if (i == dotIndex) {
            sCopy += '.';
        }
        sCopy += s[i];
    }
    if (judgeNumber(sCopy)) {
        ret.emplace_back(sCopy);
    }
    auto temp = ambiguousCoordinatesHelper(s, dotIndex - 1);
    for (int i = 0; i < temp.size(); i++) {
        ret.emplace_back(temp[i]);
    }
    return ret;
}

bool LeetCode816::judgeNumber(string s) {
    int n = s.size();
    if (n >= 2 && s[0] == '0' && (s[1] != '.' || stof(s) == 0.0f)) {
        return false;
    }
    if (s.find('.') != -1 && s.back() == '0') {
        return false;
    }
    return true;
}
