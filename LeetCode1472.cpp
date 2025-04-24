//
// Created by luzehui on 25-2-26.
//

#include "LeetCode1472.h"

BrowserHistory::BrowserHistory(std::string homepage) {
    currUrl = homepage;
}

void BrowserHistory::visit(std::string url) {
    backUrl.push(currUrl);
    currUrl = url;
    while (!forwardUrl.empty()) {
        forwardUrl.pop();
    }
}

string BrowserHistory::back(int steps) {
    while (!backUrl.empty() && steps > 0) {
        forwardUrl.push(currUrl);
        currUrl = backUrl.top();
        backUrl.pop();
        steps--;
    }
    return currUrl;
}

string BrowserHistory::forward(int steps) {
    while (!forwardUrl.empty() && steps > 0) {
        backUrl.push(currUrl);
        currUrl = forwardUrl.top();
        forwardUrl.pop();
        steps--;
    }
    return currUrl;
}
