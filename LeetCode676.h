//
// Created by 陆泽辉 on 2022/7/11.
//

#ifndef LEETCODE_LEETCODE676_H
#define LEETCODE_LEETCODE676_H

#include <vector>
#include <string>

using namespace std;

class MagicDictionary {
public:
    MagicDictionary();

    void buildDict(vector<string> dictionary);

    bool search(string searchWord);

private:
    vector<string> mDictionary;
};


#endif //LEETCODE_LEETCODE676_H
