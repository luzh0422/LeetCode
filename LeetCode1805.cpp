//
// Created by 陆泽辉 on 2022/12/6.
//

#include "LeetCode1805.h"

#include <unordered_set>

int LeetCode1805::numDifferentIntegers(string word) {
    string curr = "";
    unordered_set<string> uS;
    for (int i = 0; i < word.size(); i++) {
        if (word[i] >= '0' && word[i] <= '9') {
            if (curr == "") {
                curr += word[i];
            } else if (curr[0] == '0') {
                curr[0] = word[i];
            } else {
                curr += word[i];
            }
        } else {
            if (curr != "") {
                uS.insert(curr);
                curr = "";
            }
        }
    }
    if (curr != "") {
        uS.insert(curr);
        curr = "";
    }
    return uS.size();
}
