//
// Created by 陆泽辉 on 2022/3/13.
//

#include "LeetCode393.h"

bool LeetCode393::validUtf8(vector<int> &data) {
    int n = data.size();
    for (int i = 0; i < n; i++) {
        int curr = data[i];
        int currNext = nextCount(curr);
        if (currNext == 1 || currNext > 4 || i + currNext - 1 >= n) {
            return false;
        }
        for (int step = 1, j = i; step < currNext; step++) {
            if (!validUtf8(data[j + step])) {
                return false;
            }
        }
        i += currNext - 1;
    }
    return true;
}

int LeetCode393::nextCount(int data) {
    int nextCount = 0;
    int index = 7;
    while (index >= 0 && data / (1 << index) != 0)  {
        data %= (1 << index);
        index--;
        nextCount++;
    }
    return nextCount;
}

bool LeetCode393::validUtf8(int data) {
    return data / (1 << 6) == 2;
}
