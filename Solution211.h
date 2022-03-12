//
// Created by luzh on 2021/10/19.
//

#ifndef LEETCODE_SOLUTION211_H
#define LEETCODE_SOLUTION211_H

#include <string>
#include <vector>

using namespace std;

struct Tire {
    Tire() {
        this->children = vector<Tire*>(26, nullptr);
        this->isEnd = false;
    }
    vector<Tire*> children;
    bool isEnd;
};


class WordDictionary {
public:
    WordDictionary() {};

    void addWord(string word);

    bool search(string word);

private:
    Tire *tire = new Tire();
    bool dfs(string word, int index, Tire* node);
};


#endif //LEETCODE_SOLUTION211_H
