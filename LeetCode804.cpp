//
// Created by 陆泽辉 on 2022/4/10.
//

#include "LeetCode804.h"
#include <unordered_map>
#include <unordered_set>

int LeetCode804::uniqueMorseRepresentations(vector<string> &words) {
    unordered_map<char, string> wordsCode = {
        {'a', ".-"},{'b', "-..."},{'c', "-.-."},{'d', "-.."},{'e', "."},{'f', "..-."},{'g', "--."},{'h', "...."},{'i', ".."},{'j', ".---"},{'k', "-.-"},{'l', ".-.."},{'m', "--"},{'n', "-."},{'o', "---"},{'p', ".--."},{'q', "--.-"},{'r', ".-."},{'s', "..."},{'t', "-"},{'u', "..-"},{'v', "...-"},{'w', ".--"},{'x', "-..-"},{'y', "-.--"},{'z', "--.."}
    };
    unordered_set<string> uS = {};
    for (auto word: words) {
        string s = "";
        for (auto ch: word) {
            s += wordsCode[ch];
        }
        uS.insert(s);
    }
    return uS.size();
}
