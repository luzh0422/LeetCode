//
// Created by luzh on 2021/3/20.
//

#include "Solution150.h"
#include <stack>
#include <vector>
#include <unordered_map>

int Solution150::evalRPN(vector<string> &tokens) {
    stack<int> stk;
    for (int i = 0; i < tokens.size(); i++) {
        if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
            int firstNum = stk.top();
            stk.pop();
            int secondNum = stk.top();
            stk.pop();
            int thirdNum = 0;
            if (tokens[i] == "+") {
                thirdNum = firstNum + secondNum;
            } else if (tokens[i] == "-") {
                thirdNum = secondNum - firstNum;
            } else if (tokens[i] == "*") {
                thirdNum = firstNum * secondNum;
            } else {
                thirdNum = secondNum / firstNum;
            }
            stk.push(thirdNum);
        } else {
            int num = strToNum(tokens[i]);
            stk.push(num);
        }
    }
    return stk.top();
}

int Solution150::strToNum(string str) {
    int size = str.size();
    int num = 0;
    if (str[0] >= '0' && str[0] <= '9') {
        for (int i = 0; i < size; i++) {
            num = num * 10 + (str[i] - '0');
        }
    } else {
        for (int i = 1; i < size; i++) {
            num = num * 10 + (str[i] - '0');
        }
        num = -num;
    }
    return num;
}
