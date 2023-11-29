//
// Created by 陆泽辉 on 2023/10/11.
//

#include "LeetCode2512.h"

#include <unordered_map>
#include <sstream>

vector<int>
LeetCode2512::topStudents(vector<string> &positive_feedback, vector<string> &negative_feedback, vector<string> &report,
                          vector<int> &student_id, int k) {
    unordered_map<string, int> posHash;
    unordered_map<string, int> negHash;
    vector<int> ans;
    for (auto& it : positive_feedback) {
        ++posHash[it];
    }
    for (auto& it : negative_feedback) {
        ++negHash[it];
    }

    int n = report.size();
    vector<pair<int, int>> arr(n, pair<int, int>(0, 0)); // (score, id);
    for (int i = 0; i < n; i++) {
        string str = report[i];
        istringstream iss(str);
        vector<string> words;
        string word;
        while (iss >> word) {
            words.push_back(word);
        }
        int score = 0;
        for (auto& it : words) {
            if (posHash.count(it)) {
                score += 3;
            }
            if (negHash.count(it)) {
                score -= 1;
            }
        }
        arr[i] = {score, student_id[i]};
    }
    sort(arr.begin(), arr.end(), [&](const pair<int, int>& student1, const pair<int, int>& student2) -> bool {
        if (student1.first != student2.first) {
            return student1.first > student2.first;
        }
        return student1.second < student2.second;
    });
    for (int i = 0; i < k; ++i) {
        ans.push_back(arr[i].second);
    }
    return ans;
}
