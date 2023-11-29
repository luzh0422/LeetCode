//
// Created by 陆泽辉 on 2022/9/26.
//

#include "LeetCode708.h"

void MyLinkedList::addAtHead(int val) {
    list_.emplace_front(val);
}

void MyLinkedList::addAtTail(int val) {
    list_.emplace_back(val);
}

void MyLinkedList::addAtIndex(int index, int val) {
    if (index <= 0) {
        addAtHead(val);
    } else if (index <= list_.size()) {
        auto iter = list_.begin();
        advance(iter, index);
        list_.insert(iter, val);
    }
}

void MyLinkedList::deleteAtIndex(int index) {
    if (index >= 0 && index < list_.size()) {
        auto iter = list_.begin();
        advance(iter, index);
        list_.erase(iter);
    }
}

int MyLinkedList::get(int index) {
    if (index >= 0 && index < list_.size()) {
        auto iter = list_.begin();
        advance(iter, index);
        return *iter;
    }
    return -1;
}
