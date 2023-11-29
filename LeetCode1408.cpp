//
// Created by 陆泽辉 on 2022/8/6.
//

#include "LeetCode1408.h"
#include <unordered_map>

vector<string> LeetCode1408::stringMatching(vector<string> &words) {
    vector<string> ret = {};
    int n = words.size();
    for (int i = 0; i < n; i++) {
        string& s2 = words[i];
        vector<int> steps;
        makeNext(s2, steps);
        for (int j = 0; j < n; j++) {
            if (i != j) {
                string& s1 = words[j];
                if (KMP(s1, s2, steps) != -1) {
                    ret.push_back(s2);
                    break;
                }
            }
        }
    }
    return ret;
}

void LeetCode1408::makeNext(string &p, vector<int> &next) {
    int q,k;//q:模版字符串下标；k:最大前后缀长度
    int m = p.size();//模版字符串长度
    next.resize(m, 0);
    next[0] = 0;//模版字符串的第一个字符的最大前后缀长度为0
    /**
     * q是字符串的index；
     * k是当前index的前后缀相同长度；
     */
    for (q = 1,k = 0; q < m; ++q) {//for循环，从第二个字符开始，依次计算每一个字符对应的next值
        while(k > 0 && p[q] != p[k])//递归的求出P[0]···P[q]的最大的相同的前后缀长度k
            k = next[k-1];          //不理解没关系看下面的分析，这个while循环是整段代码的精髓所在，确实不好理解
//        if (p[q] == p[k]) { //如果相等，那么最大相同前后缀长度加1
//            k++;
//        }
        next[q] = p[q] == p[k] ? ++k : k;
    }
}

int LeetCode1408::KMP(string &s1, string &s2, vector<int>& steps) {
    int n1 = s1.size(), n2 = s2.size();
//    vector<int> steps(n, 0);
//    makeNext(s2, steps);
    /**
     * i是原始字符串的index；
     * j是匹配字符串的index；
     */
    for (int i = 0, j = 0; i < n1; i++) {
        while (j > 0 && s1[i] != s2[j]) {
            j = steps[j - 1];
        }
        if (s1[i] == s2[j]) {
            j++;
        }
        if (j == n2) {
            return i - n2 + 1;
        }
    }
    return -1;
}
