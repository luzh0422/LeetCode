//
// Created by luzehui on 2023/10/19.
//

#include "LeetCode2525.h"

string LeetCode2525::categorizeBox(int length, int width, int height, int mass) {
    const int bulkySize = 1e4, bulkySize2 = 1e9;
    const int heavySize = 100;
    bool bulky = false, heavy = false;
    if (length >= bulkySize || width >= bulkySize || height >= bulkySize || long(length) * long(width) * long(height) >= bulkySize2) {
        bulky = true;
    }
    if (mass >= heavySize) {
        heavy = true;
    }
    if (bulky && heavy) {
        return "Both";
    } else if (bulky) {
        return "Bulky";
    } else if (heavy) {
        return "Heavy";
    }
    return "Neither";
}
