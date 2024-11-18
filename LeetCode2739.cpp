//
// Created by luzehui on 2024/4/25.
//

#include "LeetCode2739.h"
#include <algorithm>

using namespace std;

int LeetCode2739::distanceTraveled(int mainTank, int additionalTank) {
    if (mainTank >= 5 && additionalTank > 0) {
        return 50 + distanceTraveled(mainTank - 4, additionalTank - 1);
    }
    return mainTank * 10;
}
