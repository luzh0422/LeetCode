//
// Created by luzh on 2021/10/29.
//

#include "Solution335.h"

bool Solution335::isSelfCrossing(vector<int> &distance) {
    int n = distance.size();
    for (int i = 3; i < n; i++) {
        /**
         *     x(1)
         *     ┌───┐
         * x(2)│   │x(0)
         *     └───┼──>
         *     x(3)│
         */
        if (distance[i - 3] >= distance[i - 1] && distance[i] >= distance[i - 2]) {
            return true;
        }
        /**
         *       x(1)
         *      ┌──────┐
         *      │      │x(0)
         *  x(2)│      ^
         *      │      │x(4)
         *      └──────│
         *        x(3)
         */
        if (i >= 4 && distance[i - 1] == distance[i - 3] && distance[i] >= distance[i- 2] - distance[i - 4]) {
            return true;
        }
        /**
         *      x(1)
         *      ┌──────┐
         *      │      │x(0)
         *  x(2)│     <│────│
         *      │       x(5)│x(4)
         *      └───────────│
         *          x(3)
         */
        if (i >= 5 && distance[i - 2] >= distance[i - 4] && distance[i - 3] >= distance[i - 1] && distance[i - 1] >= distance[i - 3] - distance[i - 5] && distance[i] >= distance[i - 2] - distance[i - 4]){
            return true;
        }
    }
    return false;
}
