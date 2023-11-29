//
// Created by 陆泽辉 on 2022/10/22.
//

#ifndef LEETCODE_LEETCODE901_H
#define LEETCODE_LEETCODE901_H

#include <vector>

using namespace std;

class StockSpanner {
public:
    StockSpanner() = default;

    int next(int price);

private:
    vector<pair<int, int>> prices;
};


#endif //LEETCODE_LEETCODE901_H
