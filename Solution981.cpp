//
// Created by luzh on 2021/7/10.
//

#include "Solution981.h"

void TimeMap::set(string key, string value, int timestamp) {
    storage[key][timestamp] = value;
}

string TimeMap::get(string key, int timestamp) {
    if (storage.count(key)) {
        auto timeMap = storage[key];
//        for (auto it = timeMap.begin(); it != timeMap.end(); it++) {
//            if (it->first <= timestamp) {
//                return it->second;
//            }
//        }
        int temp = timestamp;
        for (;temp >= timeMap.begin()->first; temp--) {
            if (timeMap.count(temp)) {
                return timeMap[temp];
            }
        }
        return "";
    } else {
        return "";
    }
}
