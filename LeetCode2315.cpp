//
// Created by 陆泽辉 on 2023/1/29.
//

#include "LeetCode2315.h"

int LeetCode2315::countAsterisks(string s) {
    int tag = 0;
    int res = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '|') {
            tag ^= 1;
        } else if (s[i] == '*' && tag == 0) {
            res++;
        }
    }
    return res;
}
