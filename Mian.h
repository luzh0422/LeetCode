//
// Created by luzehui on 2023/12/7.
//

#ifndef LEETCODE_MIAN_H
#define LEETCODE_MIAN_H

// 给定两个用链表表示的整数，每个节点包含一个数位。
// 这些数位是反向存放的，也就是个位排在链表首部。
// 编写函数对这两个整数求和，并用链表形式返回结果。
#include <list>

using namespace std;

class Mian {
public:
    list<int> addLists(list<int> l1, list<int> l2);
};


#endif //LEETCODE_MIAN_H
