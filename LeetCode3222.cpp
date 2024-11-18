//
// Created by luzehui on 2024/11/5.
//

#include "LeetCode3222.h"

string LeetCode3222::losingPlayer(int x, int y) {
    return losingPlayer(x, y, 0);
}

string LeetCode3222::losingPlayer(int x, int y, int name) {
    if (x < 1 || y < 4) {
        if (name == 0) {
            return "Bob";
        } else {
            return "Alice";
        }
    }
    return losingPlayer(x - 1, y - 4, name ^ 1);
}
