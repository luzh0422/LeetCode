//
// Created by luzh on 2022/1/27.
//

#include "Solution2047.h"

int Solution2047::countValidWords(string sentence) {
    int ans = 0;
    int start = 0, length = 0;
    int n = sentence.size();
    for (int i = 0; i < n; i++) {
        if (sentence[i] == ' ') {
            string str = sentence.substr(start, length);

            if (isWord(str)) {
                ans++;
            }
            start = i + 1;
            length = 0;
        } else {
            length++;
        }
    }
    if (length != 0) {
        string str = sentence.substr(start, length);
        if (isWord(str)) {
            ans++;
        }
    }
    return ans;
}

bool Solution2047::isWord(string s) {
    int n = s.size();
    int connectCount = 0;
    if (s == "") {
        return false;
    }
    for (int i = 0; i < n; i++) {
        char c = s[i];
        if (c >= 'a' && c <= 'z') {
            continue;
        } else if (c >= '0' && c <= '9') {
            return false;
        } else if (c == '-') {
            connectCount++;
            if (i == 0 || i == n - 1 || s[i - 1] < 'a' || s[i - 1] > 'z' || s[i +1] < 'a' || s[i + 1] > 'z' || connectCount != 1) {
                return false;
            }
        } else if (i != n - 1){
            return false;
        }
    }
    return true;
}
