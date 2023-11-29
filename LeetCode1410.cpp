//
// Created by luzehui on 2023/11/23.
//

#include "LeetCode1410.h"

string LeetCode1410::entityParser(std::string text) {
    int n = text.size();
    string res = "";
    for (int i = 0; i < n; i++) {
        if (text[i] == '&') {
            if (text[i + 1] == 'a') {
                string temp = text.substr(i, 5);
                if (temp == "&amp;") {
                    res += "&";
                    i += 4;
                } else {
                    temp = text.substr(i, 6);
                    if (temp == "&apos;") {
                        res += "'";
                        i += 5;
                    } else {
                        res += text[i];
                    }
                }
            } else if (text[i + 1] == 'q') {
                string temp = text.substr(i, 6);
                if (temp == "&quot;") {
                    res += "\"";
                    i += 5;
                } else {
                    res += text[i];
                }
            } else if (text[i + 1] == 'g') {
                string temp = text.substr(i, 4);
                if (temp == "&gt;") {
                    res += ">";
                    i += 3;
                } else {
                    res += text[i];
                }
            } else if (text[i + 1] == 'l') {
                string temp = text.substr(i, 4);
                if (temp == "&lt;") {
                    res += '<';
                    i += 3;
                } else {
                    res += text[i];
                }
            } else if (text[i + 1] == 'f') {
                string temp = text.substr(i, 7);
                if (temp == "&frasl;") {
                    res += "/";
                    i += 6;
                } else {
                    res += text[i];
                }
            } else {
                res += text[i];
            }
        } else {
            res += text[i];
        }
    }
    return res;
}
