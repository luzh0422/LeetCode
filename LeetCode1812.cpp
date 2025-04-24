//
// Created by 陆泽辉 on 2022/12/8.
//

#include "LeetCode1812.h"

bool LeetCode1812::squareIsWhite(string coordinates) {
    int col = coordinates[0] - 'a';
    int row = coordinates[1] - '1';
    return ((row & 1) ^ (col & 1)) != 0;
}
