//
// Created by 陆泽辉 on 2023/8/4.
//

#include "LeetCode722.h"

vector<string> LeetCode722::removeComments(vector<string> &source) {
    vector<string> res;
    string newLine = "";
    bool inBlock = false;
    for (auto& line : source) {
        for (int i = 0; i < line.size(); i++) {
            if (inBlock) {
                if (i + 1 < line.size() && line[i] == '*' && line[i + 1] == '/') {
                    inBlock = false;
                    i++;
                }
            } else {
                if (i + 1 < line.size() && line[i] == '/' && line[i + 1] == '*') {
                    inBlock = true;
                    i++;
                } else if (i + 1 < line.size() && line[i] == '/' && line[i + 1] == '/') {
                    break;
                } else {
                    newLine += line[i];
                }
            }
        }
        if (!inBlock && newLine != "") {
            res.push_back(newLine);
            newLine = "";
        }
    }
    return res;
}
