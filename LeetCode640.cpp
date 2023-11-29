//
// Created by 陆泽辉 on 2022/8/10.
//

#include "LeetCode640.h"

string LeetCode640::solveEquation(string equation) {
    bool leftEquation = true;
    int num = INT_MAX;
    int xCount = 0;
    int sum = 0;
    int n = equation.size();
    bool positive = true;
    for (int i = 0; i < n; i++) {
        if (equation[i] == 'x') {
            if (leftEquation) {
                if (positive) {
                    xCount += (num == INT_MAX ? 1 : num);
                } else {
                    xCount -= (num == INT_MAX ? 1 : num);
                }
            } else {
                if (positive) {
                    xCount -= (num == INT_MAX ? 1 : num);
                } else {
                    xCount += (num == INT_MAX ? 1 : num);
                }
            }
            positive = true;
            num = INT_MAX;
        } else if (equation[i] == '=') {
            if (num != INT_MAX) {
                if (positive) {
                    sum -= num;
                } else {
                    sum += num;
                }
            }
            leftEquation = false;
            positive = true;
            num = INT_MAX;
        } else if (equation[i] == '+' || equation[i] == '-') {
            if (num != INT_MAX) {
                if (leftEquation) {
                    if (positive) {
                        sum -= num;
                    } else {
                        sum += num;
                    }
                } else {
                    if (positive) {
                        sum += num;
                    } else {
                        sum -= num;
                    }
                }
            }
            positive = equation[i] == '+' ? true : false;
            num = INT_MAX;
        } else {
            if (num == INT_MAX) {
                num = 0;
            }
            num = num * 10 + equation[i] - '0';
        }
    }
    if (num != INT_MAX) {
        if (positive) {
            sum += num;
        } else {
            sum -= num;
        }
    }
    if (xCount == 0 && sum == 0) {
        return "Infinite solutions";
    } else if (xCount == 0) {
        return "No solution";
    } else {
        return "x=" + to_string(sum / xCount);
    }
}
