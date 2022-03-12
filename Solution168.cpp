//
// Created by luzh on 2021/6/29.
//

#include "Solution168.h"

#include <unordered_map>

string Solution168::convertToTitle(int columnNumber) {
    unordered_map<int, char> cache;
    for (int i = 0; i < 26; i++) {
        cache[i + 1] = 'A' + i;
    }
    string ans = "";
    while (columnNumber != 0) {
        int temp = columnNumber % 26;
        if (temp == 0) {
            temp = 26;
        }
        ans.insert(ans.begin(), cache[temp]);
        columnNumber = (columnNumber - temp)  / 26;
    }
    return ans;
}
