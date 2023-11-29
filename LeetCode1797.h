//
// Created by 陆泽辉 on 2023/2/9.
//

#ifndef LEETCODE_LEETCODE1797_H
#define LEETCODE_LEETCODE1797_H

#include <string>
#include <unordered_map>

using namespace std;

class AuthenticationManager {
public:
    AuthenticationManager(int timeToLive) : timeToLive_(timeToLive) {}

    void generate(string tokenId, int currentTime);

    void renew(string tokenId, int currentTime);

    int countUnexpiredTokens(int currentTime);

private:
    int timeToLive_;
    unordered_map<string, int> tokens;
};


#endif //LEETCODE_LEETCODE1797_H
