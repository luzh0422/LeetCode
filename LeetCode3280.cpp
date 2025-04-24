//
// Created by luzehui on 25-1-10.
//

#include "LeetCode3280.h"

string LeetCode3280::convertDateToBinary(std::string date) {
    string year = date.substr(0, 4);
    string month = date.substr(5, 2);
    string day = date.substr(8, 2);
    string yearBinary = toBinary(stoi(year));
    string monthBinary = toBinary(stoi(month));
    string dayBinary = toBinary(stoi(day));
    return yearBinary + "-" + monthBinary + "-" + dayBinary;
}

string LeetCode3280::toBinary(int num) {
    string res = "";
    while (num != 0) {
        if ((num & 1) == 1) {
            res += "1";
        } else {
            res += "0";
        }
        num /= 2;
    }
    reverse(res.begin(), res.end());
    return res;
}
