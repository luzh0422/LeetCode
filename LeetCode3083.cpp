//
// Created by luzehui on 24-12-26.
//

#include "LeetCode3083.h"
#include <unordered_set>

bool LeetCode3083::isSubstringPresent(std::string s) {
    if (s.size() < 2) {
        return false;
    }
    unordered_set<string> uS;
    string a = "";
    a += s[0];
    a += s[1];
    uS.insert(a);
    for (int i = 2; i < s.size(); i++) {
        a.erase(a.begin());
        a += s[i];
        uS.insert(a);
    }
    std::reverse(s.begin(), s.end());
    a = "";
    a += s[0];
    a += s[1];
    for (int i = 2; i < s.size(); i++) {
        if (uS.count(a)) {
            return true;
        }
        a.erase(a.begin());
        a += s[i];
    }
    if (uS.count(a)) {
        return true;
    }
    return false;
}
