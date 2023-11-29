//
// Created by 陆泽辉 on 2023/5/3.
//

#include "LeetCode1003.h"

bool LeetCode1003::isValid(string s) {
    if (s.size() == 3) {
        if (s == "abc") {
            return true;
        }
        return false;
    } else if (s.size() < 3) {
        return false;
    }
    for (int i = 0; i < s.size() - 2; i++) {
        if (s.substr(i, 3) == "abc") {
            s.erase(i, 3);
            return isValid(s);
        }
    }
    return false;
}
