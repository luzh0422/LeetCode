//
// Created by 陆泽辉 on 2022/8/2.
//

#include "LeetCode622.h"

MyCircularQueue::MyCircularQueue(int k) {
    distance = k;
    q.resize(1000, -1);
}

bool MyCircularQueue::enQueue(int value) {
    if (right - left >= distance) {
        return false;
    }
    q[right++] = value;
    return true;
}

bool MyCircularQueue::deQueue() {
    if (left == right) {
        return false;
    }
    return q[left++];
}

int MyCircularQueue::Front() {
    if (left == right) {
        return -1;
    }
    return q[left];
}

int MyCircularQueue::Rear() {
    if (left == right) {
        return -1;
    }
    return q[right - 1];
}

bool MyCircularQueue::isEmpty() {
    return left == right;
}

bool MyCircularQueue::isFull() {
    return right - left == distance;
}

