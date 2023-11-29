//
// Created by 陆泽辉 on 2022/6/4.
//

#include "LeetCode929.h"
#include <unordered_set>

int LeetCode929::numUniqueEmails(vector<string> &emails) {
    unordered_set<string> uS;
    for (auto email : emails) {
        numUniqueEmail(email);
        uS.insert(email);
    }
    return uS.size();
}

void LeetCode929::numUniqueEmail(string &email) {
    int index = 0, n = email.size(), tag = 0;
    string before = "", after = "";
    for (; index < n; index++) {
        if (email[index] == '@') {
            break;
        } else if (email[index] == '+') {
            tag = 1;
        } else if (email[index] == '.') {
            continue;
        } else if (!tag) {
            before += email[index];
        }
    }
    after = email.substr(index);
    email = before + after;
}
