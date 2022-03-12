//
// Created by luzh on 2021/3/29.
//

#include "Solution508.h"

#include <queue>

uint32_t Solution508::reverseBits(uint32_t n) {
    std::queue<int> q;
    for (int i = 0; i < 32; i++) {
        int bit = n % 2;
        n /= 2;
        q.push(bit);
    }
    uint32_t ans = 0;
    while (!q.empty()) {
        int bit = q.front();
        q.pop();
        ans = bit == 0 ? ans * 2 : ans * 2 + 1;
    }
    return ans;
}
