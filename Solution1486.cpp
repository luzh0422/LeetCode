//
// Created by luzh on 2021/5/7.
//

#include "Solution1486.h"

int Solution1486::xorOperation(int n, int start) {
    int ans = start;
    for (int i = 1; i < n; i++) {
        int temp = start + 2 * i;
        ans ^= temp;
    }
    return ans;
}
