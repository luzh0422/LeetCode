//
// Created by luzehui on 2024/3/3.
//

#ifndef LEETCODE_LEETCODE225_H
#define LEETCODE_LEETCODE225_H

#include <queue>

using namespace std;

class MyStack {
public:
    MyStack();

    void push(int x);

    int pop();

    int top();

    bool empty();

private:
    queue<int> q1, q2;
};

#endif //LEETCODE_LEETCODE225_H
