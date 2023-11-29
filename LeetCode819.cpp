//
// Created by 陆泽辉 on 2022/4/17.
//

#include "LeetCode819.h"

#include <unordered_map>
#include <unordered_set>
#include "ctype.h"

string LeetCode819::mostCommonWord(string paragraph, vector<string> &banned) {
    unordered_set<string> banneds = {};
    for (auto ban: banned) {
        ban = sToLower(ban);
        banneds.insert(ban);
    }
    string curr = "";
    unordered_map<string, int> records = {};
    for (auto para : paragraph) {
        if (para >= 'a' && para <= 'z' || para >= 'A' && para <= 'Z') {
            curr += para;
        } else {
            if (curr != "") {
                curr = sToLower(curr);
                if (!banneds.count(curr)) {
                    if (records.count(curr)) {
                        records[curr]++;
                    } else {
                        records.insert(unordered_map<string, int>::value_type(curr, 1));
                    }
                }
            }
            curr = "";
        }
    }
    if (curr != "") {
        curr = sToLower(curr);
        if (!banneds.count(curr)) {
            if (records.count(curr)) {
                records[curr]++;
            } else {
                records.insert(unordered_map<string, int>::value_type(curr, 1));
            }
        }
        curr = "";
    }
    vector<pair<string, int>> countData(records.begin(), records.end());
    sort(countData.begin(), countData.end(), [](pair<string, int>& val1, pair<string, int>& val2) -> bool {
        return val1.second > val2.second;
    });
    return countData[0].first;
}

string LeetCode819::sToLower(string &s) {
    string ret = "";
    for (auto c : s) {
        if (c >= 'A' && c <= 'Z') {
            ret += 'a' + (c - 'A');
        } else {
            ret += c;
        }
    }
    return ret;
}
