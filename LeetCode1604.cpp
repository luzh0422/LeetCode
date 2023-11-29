//
// Created by 陆泽辉 on 2023/2/7.
//

#include "LeetCode1604.h"
#include <unordered_map>

vector<string> LeetCode1604::alertNames(vector<string> &keyName, vector<string> &keyTime) {
    unordered_map<string, vector<string>> uM;
    int n = keyName.size();
    for (int i = 0; i < n; i++) {
        if (uM.count(keyName[i])) {
            uM[keyName[i]].push_back(keyTime[i]);
        } else {
            uM.insert(unordered_map<string, vector<string>>::value_type (keyName[i], {keyTime[i]}));
        }
    }
    vector<string> res;
    for (auto iter = uM.begin(); iter != uM.end(); iter++) {
        string name = iter->first;
        vector<string> times = iter->second;
        int m = times.size();
        vector<pair<int, int>> temp;
        for (int i = 0; i < m; i++) {
            temp.emplace_back(stoi(times[i].substr(0, 2)), stoi(times[i].substr(3, 2)));
        }
        std::sort(temp.begin(), temp.end(), [](pair<int, int>& temp1, pair<int, int>& temp2) -> bool {
            if (temp1.first < temp2.first) {
                return true;
            } else if (temp1.first == temp2.first) {
                return temp1.second < temp2.second;
            } else {
                return false;
            }
        });
        for (int i = 0; i < m - 2; i++) {
            if (timeDelta(temp[i], temp[i + 2]) <= 60) {
                res.push_back(name);
                break;
            }
        }
    }
    std::sort(res.begin(), res.end());
    return res;
}

int LeetCode1604::timeDelta(pair<int, int>& time1, pair<int, int>& time2) {
    int hour1 = time1.first;
    int minute1 = time1.second;
    int hour2 = time2.first;
    int minute2 = time2.second;
    return abs(hour2 * 60 + minute2 - hour1 * 60 - minute1);
}
