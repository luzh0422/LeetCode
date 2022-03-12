//
// Created by luzh on 2021/10/2.
//

#include "Solution405.h"

string Solution405::toHex(int num) {
    string ans = "";
    while (num != 0) {
        int delta = num % 16;
        if (delta > 9) {
            ans += 'a' + (delta - 9);
        } else {
            ans += to_string(delta);
        }
        num /= 16;
    }
    return ans;
}
