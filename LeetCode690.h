//
// Created by luzehui on 2024/8/27.
//

#ifndef LEETCODE_LEETCODE690_H
#define LEETCODE_LEETCODE690_H

#include <vector>

using namespace std;

class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};

class LeetCode690 {
public:
    int getImportance(vector<Employee*> employees, int id);
};


#endif //LEETCODE_LEETCODE690_H
