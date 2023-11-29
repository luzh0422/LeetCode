//
// Created by 陆泽辉 on 2022/10/19.
//

#include "LeetCode1700.h"

#include <list>

int LeetCode1700::countStudents(vector<int> &students, vector<int> &sandwiches) {
    int count = 0, n = students.size(), ret = 0;
    list<int> studentsList(students.begin(), students.end());
    list<int> sandwichesList(sandwiches.begin(), sandwiches.end());
    while (count < n) {
        if (studentsList.front() == sandwichesList.front()) {
            count = 0;
            n--;
            studentsList.pop_front();
            sandwichesList.pop_front();
            ret++;
        } else {
            count++;
            auto student = studentsList.front();
            studentsList.push_back(student);
            studentsList.pop_front();
        }
    }
    return n;
}
