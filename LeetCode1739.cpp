//
// Created by 陆泽辉 on 2022/12/25.
//

#include "LeetCode1739.h"

int LeetCode1739::minimumBoxes(int n) {
    if (n == 1) return 1;
    int floor = 1;
    int count = 1;
    int delta = 0;
    while (count < n) {
        floor += 1;
        delta = 0;
        while (delta <= floor &&  count < n) {
            count += delta;
            delta++;
        }
    }
    return floor * (floor - 1) / 2 + delta - 1;
}
