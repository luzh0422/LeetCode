//
// Created by luzehui on 2024/9/29.
//

#include "LeetCode2073.h"
#include <queue>

int LeetCode2073::timeRequiredToBuy(vector<int> &tickets, int k) {
    queue<pair<int, int>> q;
    for (int i = 0; i < tickets.size(); i++) {
        q.emplace(tickets[i], i);
    }
    int res = 0;
    while (!q.empty()) {
        auto curr = q.front();
        q.pop();
        int ticket = curr.first, index = curr.second;
        ticket--;
        res++;
        if (ticket == 0 && index == k) {
            return res;
        }
        if (ticket != 0) {
            q.emplace(ticket, index);
        }
    }
    return res;
}
