//
// Created by luzehui on 2024/3/3.
//

#include "LeetCode225.h"

MyStack::MyStack() {
}

void MyStack::push(int x) {
    if (!q1.empty() && !q2.empty()) {
        q1.push(x);
    } else if (!q1.empty()) {
        q1.push(x);
    } else {
        q2.push(x);
    }
}

bool MyStack::empty() {
    return q1.empty() && q2.empty();
}

int MyStack::pop() {
    if (!q1.empty()) {
        int temp = q1.front();
        q1.pop();
        while (!q1.empty()) {
            q2.push(temp);
            temp = q1.front();
            q1.pop();
        }
        return temp;
    } else if (!q2.empty()) {
        int temp = q2.front();
        q2.pop();
        while (!q2.empty()) {
            q1.push(temp);
            temp = q2.front();
            q2.pop();
        }
        return temp;
    }
    return -1;
}

int MyStack::top() {
    if (!q1.empty()) {
        int temp = q1.front();
        q1.pop();
        while (!q1.empty()) {
            q2.push(temp);
            temp = q1.front();
            q1.pop();
        }
        q2.push(temp);
        return temp;
    } else if (!q2.empty()) {
        int temp = q2.front();
        q2.pop();
        while (!q2.empty()) {
            q1.push(temp);
            temp = q2.front();
            q2.pop();
        }
        q1.push(temp);
        return temp;
    }
    return -1;
}


