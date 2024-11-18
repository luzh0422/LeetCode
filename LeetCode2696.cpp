//
// Created by luzehui on 2024/1/10.
//

#include "LeetCode2696.h"

int LeetCode2696::minLength(std::string s) {
    int i = 0, n = s.size();
    while (i < n - 1) {
        string temp = "";
        temp.push_back(s[i]);
        temp.push_back(s[i + 1]);
        if (temp == "AB" || temp == "CD") {
            s = s.substr(0, i) + s.substr(i + 2);
            return minLength(s);
        }
        i++;
    }
    return s.size();
}
