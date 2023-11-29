//
// Created by 陆泽辉 on 2023/9/20.
//

#include "LCP06.h"

int LCP06::minCount(vector<int> &coins) {
    int res = 0;
    for (int coin : coins)
        res += (coin + 1) / 2;
    return res;
}
