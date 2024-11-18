//
// Created by luzehui on 2024/9/30.
//

#ifndef LEETCODE_LEETCODE1845_H
#define LEETCODE_LEETCODE1845_H

#include <queue>
#include <vector>

class SeatManager {
public:
    SeatManager(int n);

    int reserve();

    void unreserve(int seatNumber);

private:
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
};

#endif //LEETCODE_LEETCODE1845_H
