//
// Created by luzh on 2021/12/30.
//

#include "Solution846.h"

bool Solution846::isNStraightHand(vector<int> &hand, int groupSize) {
    int n = hand.size();
    if (n % groupSize != 0) {
        return false;
    }
    std::sort(hand.begin(), hand.end());
    vector<int> visit(n, 0);
    for (int i = 0; i < n; i++) {
        if (!visit[i]) {
            int curr = hand[i];
            visit[i] = 1;
            int j = i + 1;
            int step = 1;
            for (; j < n && step < groupSize; j++) {
                if (!visit[j]) {
                    if (hand[j] == curr + 1) {
                        curr = hand[j];
                        visit[j] = 1;
                        step++;
                    } else if (hand[j] > curr + 1) {
                        return false;
                    }
                }
            }
            if (step != groupSize) {
                return false;
            }
        }
    }
    return true;
}
