//
// Created by luzehui on 2024/3/4.
//

#include "LeetCode232.h"

MyQueue::MyQueue() {

}

bool MyQueue::empty() {
    return stk1.empty() && stk2.empty();
}

void MyQueue::push(int x) {
    if (!stk2.empty()) {
        while (!stk2.empty()) {
            stk1.push(stk2.top());
            stk2.pop();
        }
    }
    stk1.push(x);
}

int MyQueue::peek() {
    if (!stk1.empty()) {
        int temp = stk1.top();
        stk1.pop();
        while (!stk1.empty()) {
            stk2.push(temp);
            temp = stk1.top();
            stk1.pop();
        }
        stk2.push(temp);
        return temp;
    } else if (!stk2.empty()) {
        int temp = stk2.top();
        while (!stk2.empty()) {
            stk1.push(stk2.top());
            stk2.pop();
        }
        return temp;
    }
    return -1;
}

int MyQueue::pop() {
    if (!stk1.empty()) {
        int temp = stk1.top();
        stk1.pop();
        while (!stk1.empty()) {
            stk2.push(temp);
            temp = stk1.top();
            stk1.pop();
        }
        return temp;
    } else if (!stk2.empty()) {
        int temp = stk2.top();
        stk2.pop();
        while (!stk2.empty()) {
            stk1.push(stk2.top());
            stk2.pop();
        }
        return temp;
    }
    return -1;
}
