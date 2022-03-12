//
// Created by luzh on 2021/12/28.
//

#ifndef LEETCODE_SOLUTION472_H
#define LEETCODE_SOLUTION472_H

#include <string>
#include <vector>
#include "Tire.h"

using namespace std;

//struct Tire {
//    bool isEnd;
//    vector<Tire *> children;
//    Tire() : children(26), isEnd(false) {}
//};

class Solution472 {
public:
    Solution472();
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words);

private:
    Tire* root;
    bool dfs(Tire* tire, string& word, int index = 0);
    void insert(Tire* tire, string& word);
};


#endif //LEETCODE_SOLUTION472_H
