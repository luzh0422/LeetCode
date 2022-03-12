//
// Created by luzh on 2021/11/13.
//

#include "Solution520.h"

bool Solution520::detectCapitalUse(string word) {
    int n = word.size();
    if (n < 2) {
        return true;
    }
    bool tag = word[1] >= 'A' && word[1] <= 'Z';
    if (tag && word[0] >= 'a' && word[0] <= 'z') {
        return false;
    }
    for (int i = 1; i < n; i++) {
        if (tag) {
            if (word[i] >= 'a' && word[i] <='z') {
                return false;
            }
        } else {
            if (word[i] >= 'A' && word[i] <= 'Z') {
                return false;
            }
        }
    }
    return true;
}
