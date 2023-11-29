//
// Created by luzehui on 2023/11/4.
//

#include "LeetCode187.h"
#include <unordered_map>

vector<string> LeetCode187::findRepeatedDnaSequences(std::string s) {
    unordered_map<string, int> uM;
    int n = s.size();
    vector<string> ans;
    for (int i = 0; i <= n - 10; i++) {
        string temp = s.substr(i, 10);
        if (uM.count(temp)) {
            if (uM[temp] == 1)
                ans.push_back(temp);
            uM[temp]++;
        } else {
            uM.insert(unordered_map<string, int>::value_type(temp, 1));
        }
    }
    return ans;
}
