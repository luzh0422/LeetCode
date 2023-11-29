//
// Created by 陆泽辉 on 2022/11/6.
//

#include "LeetCode1678.h"

string LeetCode1678::interpret(string command) {
    string ret = "";
    int index = 0, n = command.size();
    while (index < n) {
        if (command[index] == 'G') {
            ret += 'G';
            index++;
        } else if (command[index] == '(' && command[index + 1] == ')') {
            ret += 'o';
            index += 2;
        } else {
            ret += "al";
            index += 4;
        }
    }
    return ret;
}
