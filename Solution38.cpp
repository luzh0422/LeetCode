//
// Created by luzh on 2021/10/15.
//

#include "Solution38.h"


string Solution38::countAndSay(int n) {
    if (n == 0) return "";
    string currS = "1";
    for (int i = 1; i < n; i++) {
        string lastS = currS;
        int length = lastS.size();
        currS = "";
        for (int i = 0; i < length; i++) {
            char c = lastS[i];
            int count = countString(lastS, c, i);
            i += (count - 1);
            currS += to_string(count);
            currS += c;
        }
    }
    return currS;
}

int Solution38::countString(string &s, char c, int index) {
    int length = s.size();
    int count = 0;
    for (; index < length; index++) {
        if (s[index] != c) {
            break;
        }
        count++;
    }
    return count;
}
