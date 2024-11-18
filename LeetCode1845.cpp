//
// Created by luzehui on 2024/9/30.
//

#include "LeetCode1845.h"

SeatManager::SeatManager(int n) {
    for (int i = 1; i <= n; i++) {
        pq.push(i);
    }
}

int SeatManager::reserve() {
    auto res = pq.top();
    pq.pop();
    return res;
}

void SeatManager::unreserve(int seatNumber) {
    pq.push(seatNumber);
}
