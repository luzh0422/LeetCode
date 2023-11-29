//
// Created by 陆泽辉 on 2022/7/1.
//

#include "LeetCode241.h"

vector<int> LeetCode241::diffWaysToCompute(string expression) {
    vector<int> nums;
    vector<char> operators;
    int curr = 0, n = expression.size();
    for (int i = 0; i < n; i++) {
        if (expression[i] >= '0' && expression[i] <= '9') {
            curr += expression[i] - '0';
        } else {
            nums.emplace_back(curr);
            curr = 0;
            operators.emplace_back(expression[i]);
        }
    }
    nums.emplace_back(curr);
    vector<int> ret = {};
    backtrack(nums, operators, ret);
    return ret;
}

void LeetCode241::backtrack(vector<int> &nums, vector<char> &operators, vector<int> &ret) {
    if (operators.size() == 0) {
        ret.emplace_back(nums.front());
        return;
    }
    int n = operators.size();
    for (int i = 0; i < n; i++) {
        int first = nums[i];
        int second = nums[i + 1];
        char operation = operators[i];
        vector<int> numsCopy(nums.begin(), nums.end());
        vector<char> operatorsCopy(operators.begin(), operators.end());
        int num;
        switch (operation) {
            case '+':
                num = first + second;
                break;
            case '-':
                num = first - second;
                break;
            case '*':
                num = first * second;
                break;
            case '/':
                num = first / second;
                break;
        }
        operatorsCopy.erase(operatorsCopy.begin() + i);
        numsCopy[i] = num;
        numsCopy.erase(numsCopy.begin() + i + 1);
        backtrack(numsCopy, operatorsCopy, ret);
    }
}
