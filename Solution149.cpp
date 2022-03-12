//
// Created by luzh on 2021/6/24.
//

#include "Solution149.h"
#include <unordered_map>

int Solution149::maxPoints(vector<vector<int>> &points) {
    int size = points.size();
    if (size <= 2) {
        return size;
    }
    int ret = 0;
    for (int i = 0; i < size; i++) {
        if (ret >= size - i || ret > size / 2) {
            break;
        }
        unordered_map<int, int> mp;
        for (int j = i + 1; j < size; j++) {
            int x = points[i][0] - points[j][0];
            int y = points[i][1] - points[j][1];
            if (x == 0) {
                y = 1;
            } else if (y == 0) {
                x = 1;
            } else {
                if (y < 0) {
                    x = -x;
                    y = -y;
                }
                int gcdXY = gcd(abs(x), abs(y));
                x /= gcdXY, y /= gcdXY;
            }
            /**
             * 记录斜率相等的节点；
             */
            mp[y + x * 20001]++;
        }
        int maxn = 0;
        for (auto& [_, num]: mp) {
            maxn = max(maxn, num + 1);
        }
        ret = max(ret, maxn);
    }
    return ret;
}

/**
 * 辗转相除法求最大公约数；
 * gcb(a, b) = gcb(b, a % b);
 * @param a
 * @param b
 * @return
 */
int Solution149::gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}
