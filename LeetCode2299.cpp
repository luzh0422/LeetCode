//
// Created by 陆泽辉 on 2023/1/19.
//

#include "LeetCode2299.h"
#include <unordered_set>

bool LeetCode2299::strongPasswordCheckerII(string password) {
    if (password.size() < 8) {
        return false;
    }
    unordered_set<char> uS = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '+'};
    bool haveNumberCase = false;
    bool haveLowerCase = false;
    bool haveUpperCase = false;
    bool haveSpecialCase = false;
    char lastC = ' ';
    for (auto c : password) {
        if (c >= 'a' && c <= 'z') {
            haveLowerCase = true;
        } else if (c >= 'A' && c <= 'Z') {
            haveUpperCase = true;
        } else if (c >= '0' && c <= '9') {
            haveNumberCase = true;
        } else if (uS.count(c)) {
            haveSpecialCase = true;
        }
        if (c == lastC) {
            return false;
        }
        lastC = c;
    }
    return haveNumberCase && haveUpperCase && haveLowerCase && haveSpecialCase;
}
