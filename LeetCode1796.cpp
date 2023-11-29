//
// Created by 陆泽辉 on 2022/12/3.
//

#include "LeetCode1796.h"

int LeetCode1796::secondHighest(string s) {
    int SecondMaxVal = INT_MIN;
    int FirstMaxVal = INT_MIN;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            int num = s[i] - '0';
            if (num > FirstMaxVal) {
                SecondMaxVal = FirstMaxVal;
                FirstMaxVal = num;
            } else if (num < FirstMaxVal && num > SecondMaxVal) {
                SecondMaxVal = num;
            }
        }
    }
    return SecondMaxVal == INT_MIN ? -1 : SecondMaxVal;
}
