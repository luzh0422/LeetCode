//
// Created by luzehui on 2023/11/1.
//

#include "LeetCode2103.h"
#include <unordered_map>

int LeetCode2103::countPoints(std::string rings) {
    unordered_map<char, int> uM;
    int n = rings.size();
    for (int i = 0; i < n; i += 2) {
        char color = rings[i];
        char ring = rings[i + 1];
        if (uM.count(ring)) {
            if (color == 'R') {
                uM[ring] |= 1;
            } else if (color == 'G') {
                uM[ring] |= (1 << 1);
            } else if (color == 'B') {
                uM[ring] |= (1 << 2);
            }
        } else {
            if (color == 'R') {
                uM[ring] = 1;
            } else if (color == 'G') {
                uM[ring] = (1 << 1);
            } else if (color == 'B') {
                uM[ring] = (1 << 2);
            }
        }
    }
    int ans = 0;
    for (auto iter = uM.begin(); iter != uM.end(); iter++) {
        if (iter->second == (1 << 3) - 1) {
            ans++;
        }
    }
    return ans;
}
