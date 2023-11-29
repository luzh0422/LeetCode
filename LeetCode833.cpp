//
// Created by 陆泽辉 on 2023/8/15.
//

#include "LeetCode833.h"

#include <map>

string
LeetCode833::findReplaceString(string s, vector<int> &indices, vector<string> &sources, vector<string> &targets) {
    map<int, pair<string, string>> cache;
    int n = indices.size();
    for (int i = 0; i < n; i++) {
        cache.insert(map<int, pair<string, string>>::value_type(indices[i], {sources[i], targets[i]}));
    }
    int m = s.size();
    string res = "";
    for (int i = 0; i < m; i++) {
        if (cache.count(i)) {
            string source = cache[i].first;
            string target = cache[i].second;
            int length = source.size();
            string temp = s.substr(i, length);
            if (temp == source) {
                res += target;
                i += (length - 1);
            } else {
                res += s[i];
            }
        } else {
            res += s[i];
        }
    }
    return res;
}
