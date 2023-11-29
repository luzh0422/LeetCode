//
// Created by 陆泽辉 on 2022/5/6.
//

#ifndef LEETCODE_LEETCODE933_H
#define LEETCODE_LEETCODE933_H

#include <vector>

using namespace std;

class RecentCounter {
public:
    RecentCounter();
    int ping(int t);

private:
    vector<int> pings;
};


#endif //LEETCODE_LEETCODE933_H
