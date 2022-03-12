//
// Created by luzh on 2022/2/20.
//

#include "Solution717.h"

bool Solution717::isOneBitCharacter(vector<int> &bits) {
    int n = bits.size();
    for (int i = 0; i < n; i++) {
        if (i == n - 1) {
            return true;
        }
        if (bits[i] == 1) {
            i++;
        }
    }
    return false;
}
