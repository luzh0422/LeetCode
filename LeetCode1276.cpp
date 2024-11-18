//
// Created by luzehui on 2023/12/25.
//

#include "LeetCode1276.h"

vector<int> LeetCode1276::numOfBurgers(int tomatoSlices, int cheeseSlices) {
    if (tomatoSlices % 2 != 0 || tomatoSlices / 2 - cheeseSlices < 0 || 2 * cheeseSlices - tomatoSlices / 2 < 0) {
        return {};
    }
    return {tomatoSlices / 2 - cheeseSlices, 2 * cheeseSlices - tomatoSlices / 2};
}
