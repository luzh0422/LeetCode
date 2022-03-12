//
// Created by luzh on 2021/10/13.
//

#include "Solution412.h"

vector<string> Solution412::fizzBuzz(int n) {
    vector<string> ans = {};
    for (int i = 1; i <= n; i++) {
        if (i % 3 == 0 && i % 5 == 0) {
            ans.push_back("FizzBuzz");
        } else if (i % 3 == 0) {
            ans.push_back("Fizz");
        } else if (i % 5 == 0) {
            ans.push_back("Buzz");
        } else {
            ans.push_back(to_string(i));
        }
    }
    return ans;
}
