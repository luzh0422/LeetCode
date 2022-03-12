//
// Created by luzh on 2021/10/19.
//

#ifndef LEETCODE_TIRE_H
#define LEETCODE_TIRE_H

#include <vector>
#include <string>

using namespace std;

class Tire {
public:
    Tire();
    ~Tire() {
        children.clear();
        isEnd = false;
    }
    void insert(string word);
    bool search(string word);

    vector<Tire* > children;
    bool isEnd;
};


#endif //LEETCODE_TIRE_H
