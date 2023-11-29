//
// Created by 陆泽辉 on 2022/6/29.
//

#include "LeetCode535.h"

string LeetCode535::encode(string longUrl) {
    if (longToTiny.count(longUrl)) {
        return longToTiny[longUrl];
    }
    while(true) {
        string tinyUrl = TINYURL_PREFIX;
        for (int i = 0; i < 6; i++) {
            int index = random() % 62;
            tinyUrl += TINYURL_CODE[index];
        }
        if (!tinyToLong.count(tinyUrl)) {
            tinyToLong.insert(unordered_map<string, string>::value_type(tinyUrl, longUrl));
            longToTiny.insert(unordered_map<string, string>::value_type(longUrl, tinyUrl));
            return tinyUrl;
        }
    }
}

string LeetCode535::decode(string shortUrl) {
    if (tinyToLong.count(shortUrl)) {
        return tinyToLong[shortUrl];
    } else {
        return "";
    }
}
