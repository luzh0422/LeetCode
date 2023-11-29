//
// Created by 陆泽辉 on 2023/4/30.
//

#include "LeetCode1033.h"

vector<int> LeetCode1033::numMovesStones(int a, int b, int c) {
    int x = min({a, b, c});
    int z = max({a, b, c});
    int y = a + b + c - x - z;
    vector<int> res(2, 0);
    if (x == y - 1 && y == z - 1) {
        res[0] = 0;
    } else if (x >= y - 2 || y >= z - 2) {
        res[0] = 1;
    } else {
        res[0] = 2;
    }
    res[1] = z - x - 2;
    return res;
}
