//
// Created by luzh on 2021/10/11.
//

#include "Solution273.h"

string Solution273::numberToWords(int num) {
    if (num == 0) {
        return "zero";
    }
    int unit = 1000000000;
    int i = 0;
    string ans = "";
    while (i <= 3) {
        int curr = num / unit;
        if (curr > 0) {
            recursion(ans, curr);
            ans += units[i];
            ans += " ";
        }
        i++;
        num %= unit;
        unit /= 1000;
    }
    while (ans.back() == ' ') {
        ans.pop_back();
    }
    return ans;
}

void Solution273::recursion(string &ans, int curr) {
    if (curr == 0) {
        return;
    } else if (curr < 10) {
        ans += singles[curr];
        ans += " ";
    } else if (curr < 20) {
        ans += teens[curr - 9];
        ans += " ";
    } else if (curr < 100) {
        ans += tens[curr / 10 - 1];
        curr %= 10;
        ans += " ";
        recursion(ans, curr);
    } else {
        ans += singles[curr / 100];
        curr %= 100;
        ans += " ";
        ans += "Hundred";
        ans += " ";
        recursion(ans, curr);
    }
}
