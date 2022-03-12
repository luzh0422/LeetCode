//
// Created by luzh on 2021/7/5.
//

#include "Solution726.h"

#include <string>
#include <map>
#include <stack>
#include <iostream>

/**
 * 先解析括号中的内容，然后在解析括号外的内容
 * @param formula
 * @return
 */
string Solution726::countOfAtoms(string formula) {
    int size = formula.size();
    stack<int> stk;
    map<char, int> cache = {};
    string test;
    for (int i = 0; i < formula.size(); i++) {
        if (formula[i] == '(') {
            stk.push(i);
        } else if (formula[i] == ')') {
            int start = stk.top() + 1;
            stk.pop();
            int end = i - 1;
            int num = 0;
            int j = i + 1;
            for (; j < size; j++) {
                if (formula[j] >= '0' && formula[j] <= '9') {
                    num = num * 10 + (formula[j] - '0');
                } else {
                    break;
                }
            }
            auto temp = countOfAtoms(formula, start, end, num);
            formula = formula.replace(start - 1, j - start + 1, temp);
            test = formula;
            i = j - 1 - (j - start + 1) + temp.size();
        }
    }
    return countOfAtoms(formula, 0, formula.size() - 1, 0);
}

string Solution726::countOfAtoms(string formula, int start, int end, int num) {
    string ans = "";
    string temp = formula;
    map<char, int> cache = {};
    int count = 0;
    char lastC = '0';
    for (int i = start; i <= end; i++) {
        /**
         * 非数字；
         */
        if (formula[i] < '0' || formula[i] > '9') {
            if (lastC != '0') {
                if (cache.count(lastC)) {
                    cache[lastC] += count == 0 ? 1 : count;
                } else {
                    cache[lastC] = count == 0 ? 1 : count;
                }
                lastC = formula[i];
                count = 0;
            } else {
                lastC = formula[i];
            }
        } else {
            count = count * 10 + (formula[i] - '0');
        }
    }
    if (lastC != '0') {
        if (cache.count(lastC)) {
            cache[lastC] += count == 0 ? 1 : count;
        } else {
            cache[lastC] = count == 0 ? 1 : count;
        }
    }
    for (auto it = cache.begin(); it != cache.end(); it++) {
        int count;
        if (num != 0) {
            count = it->second * num;
        } else {
            count = it->second;
        }
        ans += it->first;
        if (count != 1) {
            ans += to_string(count);
        }
    }
    return ans;
}
