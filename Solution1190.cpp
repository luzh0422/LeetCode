//
// Created by luzh on 2021/5/26.
//

#include "Solution1190.h"

#include <stack>
#include <vector>

string Solution1190::reverseParentheses(string s) {
    stack<int> std;
    vector<vector<int>> cache;
    int size = s.size();
    for (int i = 0; i < size; i++) {
        if (s[i] == '(') {
            std.push(i);
            s.erase(s.begin() + i);
            i--;
        } else if (s[i] == ')'){
            int start = std.top();
            std.pop();
            s.erase(s.begin() + i);
            i--;
            vector<int> temp = {start, i};
            cache.push_back(temp);
        }
    }
    for (int i = 0; i < cache.size(); i++) {
        int start = cache[i][0];
        int end = cache[i][1];
        reverseString(s, start, end);
    }
    return s;
}

void Solution1190::reverseString(string& s, int start, int end) {
    while (start < end) {
        char temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        start++;
        end--;
    }
}
