//
// Created by luzh on 2021/10/11.
//

#ifndef LEETCODE_SOLUTION273_H
#define LEETCODE_SOLUTION273_H

#include <string>
#include <vector>

using namespace std;

class Solution273 {
public:
    string numberToWords(int num);

private:
    vector<string> singles = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    vector<string> teens = {"", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> tens = {"", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    vector<string> units = {"Billion", "Million", "Thousand", ""};
    void recursion(string& ans, int curr);
};


#endif //LEETCODE_SOLUTION273_H
