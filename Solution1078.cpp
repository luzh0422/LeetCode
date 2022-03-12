//
// Created by luzh on 2021/12/26.
//

#include "Solution1078.h"

vector<string> Solution1078::findOcurrences(string text, string first, string second) {
    auto texts = parseString(text);
    int n = texts.size();
    vector<string> ans = {};
    for (int i = 2; i < n; i++) {
        if (texts[i - 2] == first && texts[i - 1] == second) {
            ans.push_back(texts[i]);
        }
    }
    return ans;
}

vector<string> Solution1078::parseString(string text) {
    string temp = "";
    vector<string> ans = {};
    for (int i = 0; i < text.size(); i++) {
        if (text[i] == ' ') {
            if (temp != "") {
                ans.push_back(temp);
                temp = "";
            }
        } else {
            temp += text[i];
        }
    }
    if (temp != "") {
        ans.push_back(temp);
    }
    return ans;
}
