//
// Created by luzehui on 2024/6/29.
//

#include "LeetCode2710.h"

string LeetCode2710::removeTrailingZeros(std::string num) {
    while (num.back() == '0') {
        num.pop_back();
    }
    return num;
}
