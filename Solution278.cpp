//
// Created by luzh on 2021/6/13.
//

#include "Solution278.h"

#include <vector>

using namespace std;

bool Solution278::isBadVersion(int version) {
    return version >= badVersion;
}

int Solution278::firstBadVersion(int n) {
    int start = 1, end = n;
    int middle = (start + end) / 2;
    while (start < end) {
        if (!isBadVersion(middle)) {
            start = middle + 1;
            middle = (start + end) / 2;
        } else {
            end = middle;
            middle = (start + end) / 2;
        }
    }
    return start;
}
