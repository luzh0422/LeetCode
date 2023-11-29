//
// Created by 陆泽辉 on 2022/10/4.
//

#include "LeetCode921.h"
#include <stack>

int LeetCode921::minAddToMakeValid(string s) {
    int ret = 0;
    int count = 0;
    for (auto& c : s) {
        if (c == ')') {
            if (count == 0) {
                ret++;
            } else {
                count--;
            }
        } else if (c == '(') {
            count++;
        }
    }
    ret += count;
    return ret;
}
