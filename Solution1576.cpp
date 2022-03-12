//
// Created by luzh on 2022/1/5.
//

#include "Solution1576.h"

string Solution1576::modifyString(string s) {
    int size = s.size();
    if (s[0] == '?') {
        if (size > 1 && s[1] != '?') {
            for (int i = 0; i < 26; i++) {
                if ('a' + i != s[1]) {
                    s[0] = 'a' + i;
                    break;
                }
            }
        } else {
            s[0] = 'a';
        }
    }
    for (int i = 1; i < size - 1; i++) {
        if (s[i] == '?') {
            if (s[i + 1] != '?') {
                for (int j = 0; j < 26; j++) {
                    if ('a' + j != s[i - 1] && 'a' + j != s[i + 1]) {
                        s[i] = 'a' + j;
                        break;
                    }
                }
            } else {
                for (int j = 0; j < 26; j++) {
                    if ('a' + j != s[i - 1]) {
                        s[i] = 'a' + j;
                    }
                }
            }
        }
    }
    if (s[size - 1] == '?') {
        for (int i = 0; i < 26; i++) {
            if ('a' + i != s[size - 2]) {
                s[size - 1] = 'a' + i;
                break;
            }
        }
    }
    return s;
}
