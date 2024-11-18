//
// Created by luzehui on 2024/6/18.
//

#include "LeetCode2288.h"

#include <sstream>
#include <vector>
#include <iomanip>
#include <algorithm>

string LeetCode2288::discountPrices(std::string sentence, int discount) {
    istringstream iss(sentence);
    vector<string> words;
    string word;
    while (iss >> word) {
        words.push_back(word);
    }
    int n = words.size();
    if (n == 0) {
        return "";
    }
    string res = "";
    for (int i = 0; i < n; i++) {
        string& word = words[i];
        if (word[0] == '$' && word.size() > 1 && all_of(word.begin() + 1, word.end(), [](char c) {
            return c >= '0' && c <= '9';
        })) {
            string wordNum = "";
            double num = 0.0;
            wordNum = word.substr(1, word.size());
            num = stod(wordNum);
            num -= num * discount / 100.0;
            ostringstream oss;
            // 保留小数点后两位；
            oss << "$" << fixed << setprecision(2) << num;
            words[i] = oss.str();
        }
        res += words[i];
        res += " ";
    }
    res.pop_back();
    return res;
}
