//
// Created by 陆泽辉 on 2022/9/26.
//

#ifndef LEETCODE_LEETCODE708_H
#define LEETCODE_LEETCODE708_H

#include <list>

using namespace std;

class MyLinkedList {
public:
    MyLinkedList() = default;

    int get(int index);

    void addAtHead(int val);

    void addAtTail(int val);

    void addAtIndex(int index, int val);

    void deleteAtIndex(int index);

private:
    list<int> list_;
};

#endif //LEETCODE_LEETCODE708_H
