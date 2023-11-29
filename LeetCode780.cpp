//
// Created by 陆泽辉 on 2022/4/9.
//

#include "LeetCode780.h"
#include <algorithm>

using namespace std;

bool LeetCode780::reachingPoints(int sx, int sy, int tx, int ty) {
    while (tx > 0 && ty > 0) {
        if (sx == tx && sy == ty) {
            return true;
        }
        if (tx > ty) {
            tx -= max((tx - sx) / ty, 1) * ty;
        } else {
            ty -= max((ty - sy) / tx, 1) * tx;
        }
    }
    return false;
}
