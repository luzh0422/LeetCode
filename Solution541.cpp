//
// Created by luzh on 2021/8/20.
//

#include "Solution541.h"
#include <algorithm>

string Solution541::reverseStr(string s, int k) {
    int start = 0;
    int size = s.size();
    while (start < s.size()) {
        int end = std::min(start + k - 1, size - 1);
        reverseStr(s, start, end);
        start += 2 * k;
    }
    return s;
}

void Solution541::reverseStr(string &s, int start, int end) {
    while (start < end) {
        char c = s[start];
        s[start] = s[end];
        s[end] = c;
        start++;
        end--;
    }
    return;
}
