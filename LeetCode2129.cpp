//
// Created by luzehui on 2024/3/11.
//

#include "LeetCode2129.h"

string LeetCode2129::capitalizeTitle(std::string title) {
    string temp = "", res = "";
    int n = title.size();
    for (int i = 0; i < n; i++) {
        temp += tolower(title[i]);
        if (title[i] == ' ') {
            if (temp.size() > 3) {
                temp[0] = toupper(temp[0]);
            }
            res += temp;
            temp = "";
        }
    }
    if (temp.size() > 2) {
        temp[0] = toupper(temp[0]);
    }
    res += temp;
    return res;
}
