//
// Created by 陆泽辉 on 2023/2/9.
//

#include "LeetCode1797.h"

void AuthenticationManager::generate(string tokenId, int currentTime) {
    if (tokens.count(tokenId)) {
        tokens[tokenId] = currentTime;
    } else {
        tokens.insert(unordered_map<string, int>::value_type(tokenId, currentTime));
    }
}

void AuthenticationManager::renew(string tokenId, int currentTime) {
    if (tokens.count(tokenId)) {
        if (tokens[tokenId] + timeToLive_ > currentTime) {
            tokens[tokenId] = currentTime;
        } else {
            tokens.erase(tokenId);
        }
    }
}

int AuthenticationManager::countUnexpiredTokens(int currentTime) {
    int res = 0;
    for (auto iter = tokens.begin(); iter != tokens.end();) {
        if (iter->second + timeToLive_ > currentTime) {
            res++;
            iter++;
        } else {
            tokens.erase(iter);
        }
    }
    return res;
}
