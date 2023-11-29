//
// Created by 陆泽辉 on 2022/6/21.
//

#include "LeetCode1108.h"

string LeetCode1108::defangIPaddr(string address) {
    string ret = "";
    for (char c : address) {
        if (c == '.') {
            ret += "[.]";
        } else {
            ret += c;
        }
    }
    return ret;
}
