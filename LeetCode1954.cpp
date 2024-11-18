//
// Created by luzehui on 2023/12/26.
//

#include "LeetCode1954.h"

long long LeetCode1954::minimumPerimeter(long long neededApples) {
    if (neededApples == 0) {
        return 0;
    }
    long long n = 1;
    while (true) {
        if (2 * (n + 1) * (2 * n + 1) * n >= neededApples) {
            break;
        }
        n++;
    }
    return 8 * n;
}
