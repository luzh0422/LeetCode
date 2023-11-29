//
// Created by 陆泽辉 on 2023/3/24.
//

#ifndef LEETCODE_LEETCODE1032_H
#define LEETCODE_LEETCODE1032_H

#include <string>
#include <vector>

using namespace std;

struct Trie {
    Trie() : children(26), isEnd(false) {};
    vector<Trie*> children;
    bool isEnd;
};

class StreamChecker {
public:
    StreamChecker(vector<string>& words);

    bool query(char letter);

private:
    Trie* root;
    string searchS;
    int currNum = 0;
};

#endif //LEETCODE_LEETCODE1032_H
