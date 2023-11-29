//
// Created by 陆泽辉 on 2023/1/27.
//

#include "LeetCode2309.h"
#include <unordered_set>

string LeetCode2309::greatestLetter(string s) {
    string res = "";
    unordered_set<char> uS;
    for (auto c : s) {
        if (c >= 'a' && c <= 'z') {
            char temp = 'A' + c - 'a';
            if (uS.count(temp)) {
                if (res == "" || res < string(1, temp)) {
                    res = temp;
                }
            }
            uS.insert(c);
        } else {
            char temp = 'a' + c - 'A';
            if (uS.count(temp)) {
                if (res == "" || res < string(1, c)) {
                    res = c;
                }
            }
            uS.insert(c);
        }
    }
    return res;
}
