//
// Created by 陆泽辉 on 2022/10/31.
//

#include "LeetCode481.h"
#include <string>

int LeetCode481::magicalString(int n) {
    if (n <= 3) {
        return 1;
    }
    int ret = 0;
    std::string s = "122";
    int index = 2;
    char lastC = '2';
    while (s.size() <= n) {
        int num = s[index] - '0';
        char addC;
        if (lastC == '2') {
            addC = '1';
        } else {
            addC = '2';
        }
        lastC = addC;
        for (int i = 0; i < num; i++) {
            s += addC;
        }
        index++;
    }
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            ret++;
        }
    }
    return ret;
}
