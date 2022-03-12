//
// Created by luzh on 2021/4/14.
//

#ifndef LEETCODE_SOLUTION208_H
#define LEETCODE_SOLUTION208_H

#include <string>
#include <vector>

using namespace std;

class Trie {
public:
    /** Initialize your data structure here. */
    Trie();

    /** Inserts a word into the trie. */
    void insert(string word);

    /** Returns if the word is in the trie. */
    bool search(string word);

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix);

private:
    vector<Trie*> children;
    bool isEnd = false;
    Trie* searchPrefix(string word);
};


#endif //LEETCODE_SOLUTION208_H
