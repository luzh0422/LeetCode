//
// Created by 陆泽辉 on 2022/10/5.
//

#include "LeetCode811.h"

#include <unordered_map>

namespace {
    vector<string> parseCpdomain(string s) {
        vector<string> ret = {};
        string num = "";
        int index = 0, n = s.size();
        while (index < n) {
            if (s[index] == ' ') {
                break;
            }
            num += s[index];
            index++;
        }
        ret.emplace_back(num);
        while (index < n) {
            index++;
            if (s[index - 1] == '.' || s[index - 1] == ' ') {
                ret.emplace_back(s.substr(index));
            }
        }
        return ret;
    }
}

vector<string> LeetCode811::subdomainVisits(vector<string> &cpdomains) {
    unordered_map<string, int> records;
    for (auto cpdomain : cpdomains) {
        vector<string> temp = parseCpdomain(cpdomain);
        int num = stoi(temp[0]);
        for (int i = 1; i < temp.size(); i++) {
            if (records.count(temp[i])) {
                records[temp[i]] += num;
            } else {
                records.insert(unordered_map<string, int>::value_type (temp[i], num));
            }
        }
    }
    vector<string> ret = {};
    for (auto& record: records) {
        int num = record.second;
        string domain = record.first;
        string temp = to_string(num) + " " + domain;
        ret.push_back(temp);
    }
    return ret;
}


