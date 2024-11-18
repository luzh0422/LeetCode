//
// Created by luzehui on 2024/8/18.
//

#include "LeetCode551.h"

bool LeetCode551::checkRecord(std::string s) {
    int ACount = 0, LCount = 0;
    for (auto c : s) {
        if (c == 'A') {
            ACount++;
            if (ACount >= 2) {
                return false;
            }
            LCount = 0;
        } else if (c == 'L') {
            LCount++;
            if (LCount >= 3) {
                return false;
            }
        } else {
            LCount = 0;
        }
    }
    return true;
}
