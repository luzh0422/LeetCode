//
// Created by 陆泽辉 on 2022/9/7.
//

#include "LeetCode1592.h"
#include <vector>

string LeetCode1592::reorderSpaces(string text) {
    string curr = "";
    int spaceCount = 0;
    int n = text.size();
    vector<string> strs = {};
    for (int i = 0; i < n; i++) {
        if (text[i] == ' ') {
            spaceCount++;
            if (curr != "") {
                strs.emplace_back(curr);
                curr = "";
            }
        } else {
            curr += text[i];
        }
    }
    if (curr != "") {
        strs.emplace_back(curr);
    }
    int m = strs.size();
    int perStringSpace = spaceCount / (m - 1);
    int deltaSpace = spaceCount % (m - 1);
    string ret = "";
    for (int i = 0; i < m; i++) {
        ret += strs[i];
        if (i != m - 1) {
            for (int j = 0; j < perStringSpace; j++) {
                ret += " ";
            }
        }
    }
    for (int i = 0; i < deltaSpace; i++) {
        ret += " ";
    }
    return ret;
}
