//
// Created by luzehui on 2023/11/28.
//

#ifndef LEETCODE_LEETCODE1670_H
#define LEETCODE_LEETCODE1670_H

#include <deque>
#include <queue>

using namespace std;

class FrontMiddleBackQueue {
public:
    FrontMiddleBackQueue();

    void pushFront(int val);

    void pushMiddle(int val);

    void pushBack(int val);

    int popFront();

    int popMiddle();

    int popBack();

private:
    deque<int> lefts;
    deque<int> rights;
};


#endif //LEETCODE_LEETCODE1670_H
