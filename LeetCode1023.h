//
// Created by 陆泽辉 on 2023/4/14.
//

#ifndef LEETCODE_LEETCODE1023_H
#define LEETCODE_LEETCODE1023_H

#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

struct Trie {
    Trie() : isEnd(false) {};
    pair<char, Trie*> children{};
    bool isEnd = false;
};

class LeetCode1023 {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern);

private:
    Trie* root = nullptr;
    void buildTrie(string& pattern);
    bool searchTrie(string& query);
};


#endif //LEETCODE_LEETCODE1023_H
