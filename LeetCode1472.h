//
// Created by luzehui on 25-2-26.
//

#ifndef LEETCODE_LEETCODE1472_H
#define LEETCODE_LEETCODE1472_H

#include <string>
#include <stack>

using namespace std;

class BrowserHistory {
public:
    BrowserHistory(string homepage);

    void visit(string url);

    string back(int steps);

    string forward(int steps);

private:
    string currUrl;
    stack<string> backUrl;
    stack<string> forwardUrl;
};

#endif //LEETCODE_LEETCODE1472_H
