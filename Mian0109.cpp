//
// Created by 陆泽辉 on 2022/9/29.
//

#include "Mian0109.h"

bool Mian0109::isFlipedString(string s1, string s2) {
    if (s1.size() != s2.size()) {
        return false;
    }
    if (s1 == "" && s2 == "") {
        return true;
    }
    string temp = s1 + s1;
    auto pos = temp.find(s2);
    if (pos < temp.size()) {
        return true;
    }
    return false;
}
