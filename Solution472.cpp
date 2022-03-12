//
// Created by luzh on 2021/12/28.
//

#include "Solution472.h"


Solution472::Solution472() {
    this->root = new Tire();
}

vector<string> Solution472::findAllConcatenatedWordsInADict(vector<string> &words) {
    sort(words.begin(), words.end(), [&](const string& word1, const string& word2) -> bool {
        return word1.size() < word2.size();
    });
    int n = words.size();
    vector<string> ans = {};
    for (int i = 0; i < n; i++) {
        string word = words[i];
        /**
         * 空字符串会导致字典树的root节点的isEnd一直为true，然后在dfs时会无限递归；
         */
        if (word == "") {
            continue;
        } else if (dfs(this->root, word)) {
            ans.push_back(word);
        } else {
            insert(this->root, word);
        }
    }
    return ans;
}

bool Solution472::dfs(Tire *tire, string &word, int index) {
    int n = word.size();
    for (int i = index; i < n; i++) {
        char c = word[i];
        int cIndex = c - 'a';
        if (tire->isEnd && dfs(this->root, word, i)) {
            return true;
        }
        if (tire->children[cIndex] != nullptr) {
            tire = tire->children[cIndex];
        } else {
            return false;
        }
    }
    if (tire->isEnd) {
        return true;
    } else {
        return false;
    }
}

void Solution472::insert(Tire *tire, string &word) {
    int n = word.size();
    for (int i = 0; i < n; i++) {
        char c = word[i];
        int index = c - 'a';
        if (tire->children[index] == nullptr) {
            tire->children[index] = new Tire();
        }
        tire = tire->children[index];
    }
    tire->isEnd = true;
}
