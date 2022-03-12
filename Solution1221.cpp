//
// Created by luzh on 2021/9/7.
//

#include "Solution1221.h"

#include <vector>

int Solution1221::balancedStringSplit(string s) {
    int count = 0, lNum = 0, rNum = 0;
    for (auto& c : s) {
        if (c == 'L') {
            lNum++;
            if (lNum == rNum) {
                count = count + 1;
            }
        } else {
            rNum++;
            if (rNum == lNum) {
                count = count + 1;
            }
        }
    }
    if (rNum == lNum) {
        return count;
    } else {
        return 0;
    }
}
