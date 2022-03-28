//
// Created by luzh on 2022/3/22.
//

#include "LeetCode2038.h"

bool LeetCode2038::winnerOfGame(string colors) {
    int ACount = 0;
    int BCount = 0;
    int n = colors.size();
    for (int i = 1; i < n - 1; i++) {
        if (colors[i] == 'A' && colors[i - 1] == 'A' && colors[i + 1] == 'A') {
            ACount++;
        }
        if (colors[i] == 'B' && colors[i - 1] == 'B' && colors[i + 1] == 'B') {
            BCount++;
        }
    }
    return ACount > BCount;
}
