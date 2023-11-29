//
// Created by 陆泽辉 on 2023/9/1.
//

#include "LeetCode2240.h"
#include <set>
#include <stack>

using namespace std;

long long LeetCode2240::waysToBuyPensPencils(int total, int cost1, int cost2) {
//    set<pair<int, int>> s;
//    int res = 0;
//    s.insert({0, 0});
//    stack<pair<int, int>> st;
//    st.push({0, 0});
//    while (!st.empty()) {
//        auto [num1, num2] = st.top();
//        st.pop();
//        res++;
//        if (cost1 * (num1 + 1) + cost2 * num2 <= total && !s.count({num1 + 1, num2})) {
//            st.push({num1 + 1, num2});
//            s.insert({num1 + 1, num2});
//        }
//        if (cost1 * num1 + cost2 * (num2 + 1) <= total && !s.count({num1, num2 + 1})) {
//            st.push({num1, num2 + 1});
//            s.insert({num1, num2 + 1});
//        }
//    }

    int res = 0;
    int num1 = 0;
    while (num1 * cost1 <= total) {
        int num2 = (total - num1 * cost1) / cost2 + 1;
        res += num2;
    }
    return res;
}
