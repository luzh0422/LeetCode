//
// Created by luzh on 2022/3/7.
//

#include "Solution504.h"

string Solution504::convertToBase7(int num) {
    string ret = "";
    bool negative = false;
    if (num < 0) {
        negative = true;
        num = -num;
    } else if (num == 0) {
        return "0";
    }
    while (num != 0) {
        ret.insert(0, to_string(num % 7));
        num /= 7;
    }
    if (negative) {
        ret.insert(0, "-");
    }
    return ret;
}
