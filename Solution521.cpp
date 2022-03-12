//
// Created by luzh on 2022/3/5.
//

#include "Solution521.h"
#include <algorithm>

int Solution521::findLUSLength(string a, string b) {
    int aSize = a.size(), bSize = b.size();
    if (a.size() != b.size()) {
        return max(aSize, bSize);
    }
    bool isSame = true;
    for (int i = 0; i < aSize; i++) {
        if (a[i] != b[i]) {
            isSame = false;
            break;
        }
    }
    if (!isSame) {
        return max(aSize, bSize);
    } else {
        return -1;
    }
}
