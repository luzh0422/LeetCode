//
// Created by luzh on 2021/9/12.
//

#include "Solution678.h"

#include <stack>

bool Solution678::checkValidString(string s) {
    int leftBraveCount = 0;
    stack<int> leftBraveStk;
    stack<int> starBraveStk;
    int starCount = 0;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            leftBraveCount++;
            leftBraveStk.push(i);
        } else if (s[i] == ')') {
            if (leftBraveCount == 0) {
                if (starCount == 0) {
                    return false;
                } else {
                    starCount--;
                    int index = starBraveStk.top();
                    starBraveStk.pop();
                    s[index] = '.';
                }
            } else {
                leftBraveCount--;
                int index = leftBraveStk.top();
                leftBraveStk.pop();
                s[index] = '.';
            }
        } else {
            starCount++;
            starBraveStk.push(i);
        }
    }
    if (starCount >= leftBraveCount) {
        leftBraveCount = 0;
        starCount = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                leftBraveCount++;
            } else if (s[i] == '*') {
                if (leftBraveCount > 0) {
                    leftBraveCount--;
                }
            }
        }
        return leftBraveCount == 0;
    } else {
        return false;
    }
}

bool Solution678::checkValidString(string s, int leftBraveCount, int start, int end) {
    for (int i = start; i <= end; i++) {
        if (s[i] == '(') {
            leftBraveCount++;
        } else if (s[i] == ')') {
            if (leftBraveCount != 0) {
                leftBraveCount--;
            } else {
                return false;
            }
        } else if (s[i] == '*') {
            /**
             * '*' 代表'('
             */
            leftBraveCount++;
            if (checkValidString(s, leftBraveCount, i + 1, end)) {
                return true;
            }
            /**
             * '*' 不代表括号
             */
            leftBraveCount--;
            if (checkValidString(s, leftBraveCount, i + 1, end)) {
                return true;
            }
            leftBraveCount--;
            if (checkValidString(s, leftBraveCount, i + 1, end)) {
                return true;
            }
            return false;
        }
    }
    return leftBraveCount == 0;
}
