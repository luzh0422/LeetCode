//
// Created by 陆泽辉 on 2022/12/30.
//

#ifndef LEETCODE_LEETCODE855_H
#define LEETCODE_LEETCODE855_H

#include <set>

using namespace std;

class ExamRoom {
public:
    ExamRoom(int n);

    int seat();

    void leave(int p);

private:
    int _n;
    set<int> _seated;
};



#endif //LEETCODE_LEETCODE855_H
