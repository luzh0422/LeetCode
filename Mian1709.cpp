//
// Created by 陆泽辉 on 2022/9/28.
//

#include "Mian1709.h"

#include <queue>
#include <unordered_set>

using namespace std;

int Mian1709::getKthMagicNumber(int k) {

    priority_queue<long, vector<long>, greater<long>> pq;
    unordered_set<long> us;
    pq.emplace(1);
    int index = 0;
    long ret;
    while (index < k && !pq.empty()) {
        index++;
        ret = pq.top();
        pq.pop();
        if (!us.count(ret * 3)) {
            pq.emplace(ret * 3);
            us.emplace(ret * 3);
        }
        if (!us.count(ret * 5)) {
            pq.emplace(ret * 5);
            us.emplace(ret * 5);
        }
        if (!us.count(ret * 7)) {
            pq.emplace(ret * 7);
            us.emplace(ret * 7);
        }
    }
    return ret;
}
