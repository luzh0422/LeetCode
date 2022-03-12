//
// Created by luzh on 2021/10/4.
//

#include "Solution482.h"

#include <unordered_map>

string Solution482::licenseKeyFormatting(string s, int k) {
    int n = 0;
    int curr = 0;
    int sSize = s.size();
    for (int j = 0; j < sSize; j++) {
        if (s[j] != '-') {
            n++;
        }
    }
    string ans = "";
    int first = n % k;
    int index = 0;
    int i = 0;
    if (first != 0) {
        for (; i < sSize; i++) {
            if (s[i] != '-') {
                index++;
                curr++;
                ans.push_back(lowerToUpper(s[i]));
            }
            if (index == first) {
                if (curr != n) {
                    ans.push_back('-');
                }
                index = 0;
                i++;
                break;
            }
        }
    }
    for (; i < sSize; i++) {
        if (s[i] != '-') {
            index++;
            curr++;
            ans.push_back(lowerToUpper(s[i]));
        }
        if (index == k) {
            if (curr != n) {
                ans.push_back('-');
            }
            index = 0;
        }
    }
    return ans;
}

char Solution482::lowerToUpper(char c) {
    unordered_map<char, char> um = {{'a', 'A'}, {'b', 'B'}, {'c', 'C'}, {'d', 'D'}, {'e', 'E'}, {'f', 'F'}, {'g', 'G'}, {'h', 'H'}, {'i', 'I'}, {'j', 'J'}, {'k', 'K'}, {'l', 'L'}, {'m', 'M'}, {'n', 'N'}, {'o', 'O'}, {'p', 'P'}, {'q', 'Q'}, {'r', 'R'}, {'s', 'S'}, {'t', 'T'}, {'u', 'U'}, {'v', 'V'}, {'w', 'W'}, {'x', 'X'}, {'y', 'Y'}, {'z', 'Z'}};
    if (um.count(c)) {
        return um[c];
    } else {
        return c;
    }
}
