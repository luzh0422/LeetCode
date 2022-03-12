//
// Created by luzh on 2021/8/17.
//

#include "Solution551.h"

bool Solution551::checkRecord(string s) {
    int ACount = 0;
    int LIndex = 0;
    int LCount = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'P') {
            continue;
        } else if (s[i] == 'A') {
            ACount++;
            if (ACount >= 2) {
                return false;
            }
        } else if (s[i] == 'L') {
            if (i - 1 == LIndex) {
                LCount++;
                if (LCount >= 3) {
                    return false;
                }
            } else {
                LCount = 1;
            }
            LIndex = i;
        }
    }
    return true;
}
