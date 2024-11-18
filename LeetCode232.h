//
// Created by luzehui on 2024/3/4.
//

#ifndef LEETCODE_LEETCODE232_H
#define LEETCODE_LEETCODE232_H

#include <stack>

using namespace std;

class MyQueue {
public:
    MyQueue();

    void push(int x);

    int pop();

    int peek();

    bool empty();

private:
    stack<int> stk1, stk2;
};

#endif //LEETCODE_LEETCODE232_H
