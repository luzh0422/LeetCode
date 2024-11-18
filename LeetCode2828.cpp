//
// Created by luzehui on 2023/12/20.
//

#include "LeetCode2828.h"

bool LeetCode2828::isAcronym(vector<std::string> &words, std::string s) {
    string temp = "";
    for (auto& word : words) {
        temp += word[0];
    }
    return temp == s;
}
