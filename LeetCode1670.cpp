//
// Created by luzehui on 2023/11/28.
//

#include "LeetCode1670.h"

FrontMiddleBackQueue::FrontMiddleBackQueue() {

}

void FrontMiddleBackQueue::pushFront(int val) {
    lefts.push_front(val);
    if (lefts.size() == rights.size() + 2) {
        rights.push_front(lefts.back());
        lefts.pop_back();
    }
}

void FrontMiddleBackQueue::pushMiddle(int val) {
    if (lefts.size() == rights.size() + 1) {
        rights.push_front(lefts.back());
        lefts.pop_back();
    }
    lefts.push_back(val);
}

void FrontMiddleBackQueue::pushBack(int val) {
    rights.push_back(val);
    if (lefts.size() + 1 == rights.size()) {
        lefts.push_back(rights.front());
        rights.pop_front();
    }
}

int FrontMiddleBackQueue::popFront() {
    if (lefts.empty()) {
        return -1;
    }
    int val = lefts.front();
    lefts.pop_front();
    if (lefts.size() + 1 == rights.size()) {
        lefts.push_back(rights.front());
        rights.pop_front();
    }
    return val;
}

int FrontMiddleBackQueue::popMiddle() {
    if (lefts.empty()) {
        return -1;
    }
    int val = lefts.back();
    lefts.pop_back();
    if (lefts.size() + 1 == rights.size()) {
        lefts.push_back(rights.front());
        rights.pop_front();
    }
    return val;
}

int FrontMiddleBackQueue::popBack() {
    if (lefts.empty()) {
        return -1;
    }
    int val;
    if (rights.empty()) {
        val = lefts.back();
        lefts.pop_back();
    } else {
        val = rights.back();
        rights.pop_back();
        if (lefts.size() == rights.size() + 2) {
            rights.push_front(lefts.back());
            lefts.pop_back();
        }
    }
    return val;
}

