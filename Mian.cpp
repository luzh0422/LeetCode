//
// Created by luzehui on 2023/12/7.
//

#include "Mian.h"

#include <stack>

list<int> Mian::addLists(list<int> l1, list<int> l2) {
    auto node1 = l1.begin(), node2 = l2.begin();
    list<int> res;
    int temp = 0;
    while (node1 != l1.end() && node2 != l2.end()) {
        int num = *node1 + *node2 + temp;
        temp = num / 10;
        num %= 10;
        node1++;
        node2++;
        res.push_back(num);
    }
    while (node1 != l1.end()) {
        int num = *node1 + temp;
        temp = num / 10;
        num %= 10;
        node1++;
        res.push_back(num);
    }
    while (node2 != l2.end()) {
        int num = *node2 + temp;
        temp = num / 10;
        num %= 10;
        node2++;
        res.push_back(num);
    }
    if (temp != 0) {
        res.push_back(temp);
    }
    return res;
}
