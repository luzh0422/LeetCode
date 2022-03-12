//
// Created by luzh on 2021/5/20.
//

#include "Solution692.h"

#include <map>

vector<string> Solution692::topKFrequent(vector<string> &words, int k) {
    map<string, int> record = {};
    vector<string> ans = {};
    for (int i = 0; i < words.size(); i++) {
        if (record.count(words[i])) {
            record[words[i]] ++;
        } else {
            record.insert(map<string, int>::value_type(words[i], 1));
            ans.emplace_back(words[i]);
        }
    }
    sort(ans.begin(), ans.end(), [&record](string& s1, string& s2) -> bool {
        return record[s1] > record[s2] || record[s1] == record[s2] && s1 < s2;
    });
    ans.resize(k);
    return ans;
}
