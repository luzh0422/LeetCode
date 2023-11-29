//
// Created by 陆泽辉 on 2022/6/29.
//

#ifndef LEETCODE_LEETCODE535_H
#define LEETCODE_LEETCODE535_H

#include <string>
#include <unordered_map>

using namespace std;

class LeetCode535 {
public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl);

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl);

private:
    const string TINYURL_PREFIX = "https://tinyurl.com/";
    const string TINYURL_CODE = "1234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    unordered_map<string, string> longToTiny;
    unordered_map<string, string> tinyToLong;
};

#endif //LEETCODE_LEETCODE535_H
