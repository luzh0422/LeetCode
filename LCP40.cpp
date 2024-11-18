//
// Created by luzehui on 2024/8/1.
//

#include "LCP40.h"
#include <queue>

int LCP40::maxmiumScore(vector<int> &cards, int cnt) {
    priority_queue<int, vector<int>, less<int>> oddPq, evenPq;
    for (auto& card : cards) {
        if ((card & 1) != 0) {
            oddPq.push(card);
        } else {
            evenPq.push(card);
        }
    }
    int res = 0;
    while (cnt > 0) {
        if (cnt > 1) {
            int oddNum1 = 0, oddNum2 = 0, evenNum1 = 0, evenNum2 = 0;
            if (!oddPq.empty()) {
                oddNum1 = oddPq.top();
                oddPq.pop();
            }
            if (!oddPq.empty()) {
                oddNum2 = oddPq.top();
                oddPq.pop();
            }
            if (oddNum2 == 0) {
                if (!evenPq.empty()) {
                    evenNum1 = evenPq.top();
                    evenPq.pop();
                }
                if (!evenPq.empty()) {
                    evenNum2 = evenPq.top();
                    evenPq.pop();
                }
                res += evenNum1 + evenNum2;
                if (evenNum2 == 0) {
                    break;
                }
            } else {
                if (!evenPq.empty()) {
                    evenNum1 = evenPq.top();
                    evenPq.pop();
                }
                if (!evenPq.empty()) {
                    evenNum2 = evenPq.top();
                    evenPq.pop();
                }
                if (oddNum1 + oddNum2 >= evenNum1 + evenNum2 ||
                    (cnt > 2 && evenNum2 == 0)) {
                    res += oddNum1 + oddNum2;
                    evenPq.push(evenNum2);
                    evenPq.push(evenNum1);
                } else {
                    res += evenNum1 + evenNum2;
                    oddPq.push(oddNum2);
                    oddPq.push(oddNum1);
                }
            }
            cnt -= 2;
        } else {
            if (evenPq.empty()) {
                break;
            }
            res += evenPq.top();
            cnt--;
        }
    }
    return cnt > 0 ? 0 : res;
}
