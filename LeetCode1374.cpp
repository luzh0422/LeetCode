//
// Created by 陆泽辉 on 2022/8/1.
//

#include "LeetCode1374.h"

string LeetCode1374::generateTheString(int n) {
    string ret = "";
    if (n % 2 == 0) {
        for (int i = 0; i < n / 2 - 1; i++) {
            ret += "a";
        }
        for (int i = 0; i < n / 2 + 1; i++) {
            ret += "b";
        }
    } else {
        for (int i = 0; i < n; i++) {
            ret += "a";
        }
    }
    return ret;
}
