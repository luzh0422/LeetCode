//
// Created by 陆泽辉 on 2023/1/12.
//

#include "LeetCode1807.h"

string LeetCode1807::evaluate(string s, vector<vector<string>> &knowledge) {
    unordered_map<string, string> uS;
    for (auto &k : knowledge) {
        uS.emplace(k[0], k[1]);
    }
    int n = s.size();
    string res = "";
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            int j = i + 1;
            string temp = "";
            while (j < n && s[j] != ')') {
                temp += s[j];
                j++;
            }
            evaluate(temp, uS);
            res += temp;
            i = j;
        } else {
            res += s[i];
        }
    }
    return res;
}

void LeetCode1807::evaluate(string &s, unordered_map<string, string> &dictionary) {
    if (dictionary.count(s)) {
        s = dictionary[s];
    } else {
        s = "?";
    }
}
