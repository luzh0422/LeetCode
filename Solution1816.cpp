//
// Created by luzh on 2021/12/6.
//

#include "Solution1816.h"
#include <vector>

string Solution1816::truncateSentence(string s, int k) {
    vector<string> sArr = {};
    int n = s.size();
    string currS = "";
    for (int i = 0; i < n; i++) {
        if (s[i] == ' ') {
            sArr.push_back(currS);
            currS = "";
        } else {
            currS += s[i];
        }
    }
    if (currS != "") {
        sArr.push_back(currS);
        currS = "";
    }
    for (int i = 0; i < k; i++) {
        currS += sArr[i];
        currS += ' ';
    }
    currS.resize(currS.size() - 1);
    return currS;
}
