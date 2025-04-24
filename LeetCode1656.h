//
// Created by luzehui on 25-2-24.
//

#ifndef LEETCODE_LEETCODE1656_H
#define LEETCODE_LEETCODE1656_H

#include <string>
#include <vector>

using namespace std;

class OrderedStream {
public:
    OrderedStream(int n);

    vector<string> insert(int idKey, string value);

private:
    vector<string> values;
    int ptr = 1;
};

#endif //LEETCODE_LEETCODE1656_H
