//
// Created by luzehui on 2023/11/29.
//

#ifndef LEETCODE_LEETCODE2336_H
#define LEETCODE_LEETCODE2336_H

#include <set>

using namespace std;

class SmallestInfiniteSet {
public:
    SmallestInfiniteSet();

    int popSmallest();

    void addBack(int num);

private:
    int curr_ = 1;
    set<int> minVals{};
};


#endif //LEETCODE_LEETCODE2336_H
