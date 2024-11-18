//
// Created by luzehui on 2024/7/15.
//

#include "LeetCode721.h"
#include <unordered_map>

class UnionFind {
private:
    vector<int> parents, ranks;
    int n;

public:
    UnionFind(int _n) {
        n = _n;
        for (int i = 0; i < n; i++) {
            parents.push_back(i);
            ranks.push_back(0);
        }
    }

    int find(int x) {
        if (x == parents[x]) {
            return x;
        }
        return parents[x] = find(parents[x]);
    }

    void UnionSet(int x, int y) {
        int xParent = find(x);
        int yParent = find(y);
        if (xParent == yParent) {
            return;
        }
        if (ranks[xParent] > ranks[yParent]) {
            parents[yParent] = xParent;
        } else {
            if (ranks[xParent] == ranks[yParent]) {
                ranks[yParent]++;
            }
            parents[xParent] = yParent;
        }
    }
};

vector<vector<string>> LeetCode721::accountsMerge(vector<vector<std::string>> &accounts) {
    unordered_map<string, int> emailToIndex;
    unordered_map<string, string> emailToName;
    int emailCount = 0;
    for (auto& account : accounts) {
        string name = account[0];
        int n = account.size();
        for (int i = 1; i < n; i++) {
            if (!emailToIndex.count(account[i])) {
                emailToIndex.insert(unordered_map<string, int>::value_type(account[i], emailCount++));
                emailToName.insert(unordered_map<string, string>::value_type(account[i], name));
            }
        }
    }
    UnionFind uf(emailCount);
    for (auto& account : accounts) {
        string firstEmail = account[1];
        int firstIndex = emailToIndex[firstEmail];
        for (int i = 2; i < account.size(); i++) {
            string secondEmail = account[i];
            int secondIndex = emailToIndex[secondEmail];
            uf.UnionSet(firstIndex, secondIndex);
        }
    }

    unordered_map<int, vector<string>> indexToEmails;
    for (auto iter = emailToIndex.begin(); iter != emailToIndex.end(); iter++) {
        int index = uf.find(iter->second);
        indexToEmails[index].emplace_back(iter->first);
    }

    vector<vector<string>> ans;
    for (auto iter = indexToEmails.begin(); iter != indexToEmails.end(); iter++) {
        auto emails = iter->second;
        std::sort(emails.begin(), emails.end());
        string name = emailToName[emails[0]];
        vector<string> account{};
        account.push_back(name);
        account.insert(account.begin(), emails.begin(), emails.end());
        ans.push_back(account);
    }
    return ans;
}
