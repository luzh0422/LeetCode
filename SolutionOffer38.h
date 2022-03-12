//
// Created by luzh on 2021/6/22.
//

#ifndef LEETCODE_SOLUTIONOFFER38_H
#define LEETCODE_SOLUTIONOFFER38_H

#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class SolutionOffer38 {
public:
    vector<string> permutation(string s);

private:
    void permutation(string s, string& currString, vector<string>& ans, int curr, unordered_map<string, int>& cache);
};


#endif //LEETCODE_SOLUTIONOFFER38_H
