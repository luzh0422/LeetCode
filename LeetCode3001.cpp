//
// Created by luzehui on 24-12-5.
//

#include "LeetCode3001.h"
#include <algorithm>

int LeetCode3001::minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
    if (a == e && (c != e || d < std::min(b, f) || d > std::max(b, f)) ||
        b == f && (d != f || c < std::min(a, e) || c > std::max(a, e))) {
        return 1;
    }
    if (e != c && f - d == e - c &&
        ((f - b) / (e - a) != 1 || a < std::min(c, e) ||
         a > std::max(c, e))) {
        return 1;
    }
    if (e != c && f - d == c - e &&
        ((f - b) / (e - a) != -1 || a < std::min(c, e) ||
         a > std::max(c, e))) {
        return 1;
    }
    return 2;
}
