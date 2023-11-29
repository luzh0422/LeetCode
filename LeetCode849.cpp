//
// Created by 陆泽辉 on 2023/8/22.
//

#include "LeetCode849.h"

int LeetCode849::maxDistToClosest(vector<int> &seats) {
    vector<int> seateds;
    int n = seats.size();
    for (int i = 0; i < n; i++) {
        if (seats[i] == 1) {
            seateds.push_back(i);
        }
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (seats[i] == 0) {
            auto forward = std::upper_bound(seateds.begin(), seateds.end(), i);
            if (forward == seateds.begin()) {
                res = max(res, *forward - i);
            } else if (forward == seateds.end()) {
                advance(forward, -1);
                res = max(res, i - *forward);
            } else {
                auto backward = forward;
                advance(backward, -1);
                res = max(res, min(i - *backward, *forward - i));
            }
        }
    }
    return res;
}
