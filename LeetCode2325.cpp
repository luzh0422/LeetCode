//
// Created by 陆泽辉 on 2023/2/1.
//

#include "LeetCode2325.h"
#include <unordered_map>

string LeetCode2325::decodeMessage(string key, string message) {
    int index = 0;
    unordered_map<char, char> uM;
    for (auto c : key) {
        if (c != ' ' && !uM.count(c)) {
            uM.insert(unordered_map<char, char>::value_type (c, 'a' + index));
            index++;
        }
    }
    for (auto &c : message) {
        if (uM.count(c)) {
            c = uM[c];
        }
    }
    return message;
}
