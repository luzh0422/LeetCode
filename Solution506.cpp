//
// Created by luzh on 2021/12/2.
//

#include "Solution506.h"
#include <map>

vector<string> Solution506::findRelativeRanks(vector<int> &score) {
    int n = score.size();
    map<int, int, greater<int>> cache;
    for (int i = 0; i < n; i++) {
        if (cache.count(score[i])) {
            cache[score[i]] = i;
        } else {
            cache.insert(map<int, int, greater<int>>::value_type(score[i], i));
        }
    }
    int temp = 0;
    for (auto it = cache.begin(); it != cache.end(); it++) {
        it->second = temp;
        temp++;
    }
    vector<string> ans = {};
    for (int i = 0; i < n; i++) {
        int index = cache[score[i]];
        if (index == 0) {
            ans.push_back("Gold Medal");
        } else if (index == 1) {
            ans.push_back("Silver Medal");
        } else if (index == 2) {
            ans.push_back("Bronze Medal");
        } else {
            ans.push_back(to_string(index + 1));
        }
    }
    return ans;
}
