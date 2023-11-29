//
// Created by 陆泽辉 on 2022/8/21.
//

#include "LeetCode1455.h"

int LeetCode1455::isPrefixOfWord(string sentence, string searchWord) {
    int left = 0, right = 0;
    int index = 1;
    while (right < sentence.size()) {
        if (sentence[right] == ' ') {
            string s = sentence.substr(left, right - left);
            if (isPerfixOfWord(s , searchWord)) {
                return index;
            }
            left = right + 1;
            right = left;
            index++;
        } else {
            right++;
        }
    }
    if (left != right) {
        string s = sentence.substr(left, right - left);
        if (isPerfixOfWord(s , searchWord)) {
            return index;
        }
    }
    return -1;
}

bool LeetCode1455::isPerfixOfWord(string &s, string &searchWord) {
    int start = 0;
    while (start < s.size() && start < searchWord.size()) {
        if (s[start] != searchWord[start]) {
            break;
        }
        start++;
    }
    if (start == searchWord.size()) {
        return true;
    } else {
        return false;
    }
}
