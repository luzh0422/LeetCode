//
// Created by luzh on 2022/1/6.
//

#include "Solution71.h"
#include <stack>

string Solution71::simplifyPath(string path) {
    stack<string> stk;
    string temp = "";
    int n = path.size();
    for (int i = 0; i < n; i++) {
        if (path[i] == '/') {
            if (temp == "..") {
                if (!stk.empty()) {
                    stk.pop();
                }
            } else if (temp != "." && temp != "") {
                stk.push(temp);
            }
            temp = "";
        } else {
            temp += path[i];
        }
    }
    if (temp != "" && temp != "/") {
        if (temp == "..") {
            if (!stk.empty()) {
                stk.pop();
            }
        } else if (temp != ".") {
            stk.push(temp);
        }
        temp = "";
    }
    temp += '/';
    while (!stk.empty()) {
        string curr = "/";
        curr += stk.top();
        stk.pop();
        temp.insert(0, curr);
    }
    if (temp.size() > 1) {
        temp.erase(temp.size() - 1);
    }
    return temp;
}
