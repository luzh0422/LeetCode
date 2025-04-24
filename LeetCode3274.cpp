//
// Created by luzehui on 24-12-3.
//

#include "LeetCode3274.h"

bool LeetCode3274::checkTwoChessboards(std::string coordinate1, std::string coordinate2) {
    int coordinateNum1 = ((coordinate1[0] - 'a') & 1) ^ ((coordinate1[1] - '1') & 1);
    int coordinateNum2 = ((coordinate2[0] - 'a') & 1) ^ ((coordinate2[1] - '1') & 1);
    return !(coordinateNum1 ^ coordinateNum2);
}
