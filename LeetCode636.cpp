//
// Created by 陆泽辉 on 2022/8/7.
//

#include "LeetCode636.h"
#include <unordered_map>
#include <stack>
struct execution {
    int startTime;
    int level;
    int pid;
};

vector<int> LeetCode636::exclusiveTime(int n, vector<string> &logs) {
    stack<execution*> curr;
    vector<int> ret(n, 0);
    int logsN = logs.size();
    for (int i = 0; i < logsN; i++) {
        string log = logs[i];
        vector<string> parsed = parseLog(log);
        string startOrEnd = parsed[1];
        if (curr.empty()) {
            execution* ex = new execution();
            ex->startTime = stoi(parsed[2]);
            ex->pid = stoi(parsed[0]);
            ex->level = 1;
            curr.push(ex);
        } else {
            int currPid = stoi(parsed[0]);
            int topPid = curr.top()->pid;
            if (startOrEnd == "start") {
                if (topPid == currPid) {
                    curr.top()->level++;
                } else {
                    execution* ex = new execution();
                    ex->startTime = stoi(parsed[2]);
                    ex->pid = stoi(parsed[0]);
                    ex->level = 1;
                    ret[curr.top()->pid] += stoi(parsed[2]) - curr.top()->startTime;
                    curr.push(ex);
                }
            } else {
                curr.top()->level--;
                if (curr.top()->level == 0) {
                    int currTime = stoi(parsed[2]);
                    ret[curr.top()->pid] += currTime - curr.top()->startTime + 1;
                    curr.pop();
                    if (!curr.empty()) {
                        curr.top()->startTime = currTime + 1;
                    }
                }
            }
        }
    }
    return ret;
}

vector<string> LeetCode636::parseLog(string &log) {
    vector<string> ret = {};
    int n = log.size();
    string curr = "";
    for (int i = 0; i < n; i++) {
        if (log[i] == ':') {
            ret.push_back(curr);
            curr = "";
        } else {
            curr += log[i];
        }
    }
    ret.push_back(curr);
    return ret;
}
