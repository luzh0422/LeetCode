//
// Created by 陆泽辉 on 2022/8/2.
//

#ifndef LEETCODE_LEETCODE622_H
#define LEETCODE_LEETCODE622_H

#include <vector>

using namespace std;

class MyCircularQueue {
public:
    MyCircularQueue(int k);

    bool enQueue(int value);

    bool deQueue();

    int Front();

    int Rear();

    bool isEmpty();

    bool isFull();

private:
    vector<int> q;
    int left = 0;
    int right = 0;
    int distance = 0;
};


#endif //LEETCODE_LEETCODE622_H
