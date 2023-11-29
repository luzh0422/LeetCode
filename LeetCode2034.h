//
// Created by 陆泽辉 on 2023/10/8.
//

#ifndef LEETCODE_LEETCODE2034_H
#define LEETCODE_LEETCODE2034_H

#include <queue>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

struct cmp1 {
    bool operator() (const pair<int, int>& p1, const pair<int, int>& p2) {
        return p1.second > p2.second;
    }
};

struct cmp2 {
    bool operator() (const pair<int, int>& p1, const pair<int, int>& p2) {
        return p1.second < p2.second;
    }
};

class StockPrice {
public:
    StockPrice() = default;

    void update(int timestamp, int price);

    int current();

    int maximum();

    int minimum();

private:
    multiset<int> stocks;
    unordered_map<int, int> cache;
    int _timestamp = -1;
    int _price = -1;
};
#endif //LEETCODE_LEETCODE2034_H
