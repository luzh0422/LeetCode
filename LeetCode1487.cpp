//
// Created by 陆泽辉 on 2023/3/3.
//

#include "LeetCode1487.h"
#include <unordered_map>

vector<string> LeetCode1487::getFolderNames(vector<string> &names) {
    unordered_map<string, int> uM;
    vector<string> res;
    for (auto name : names) {
        if (uM.count(name)) {
            int num = uM[name];
            while (true) {
                num++;
                string newName = name + "(" + to_string(num) + ")";
                if (uM.count(newName)) {
                    continue;
                }
                res.emplace_back(newName);
                uM.emplace(newName, 0);
                uM[name] = num;
                break;
            }
        } else {
            res.emplace_back(name);
            uM.emplace(name, 0);
        }
    }
    return res;
}
