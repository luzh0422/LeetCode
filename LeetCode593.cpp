//
// Created by 陆泽辉 on 2022/7/29.
//

#include "LeetCode593.h"
#include <string>
#include <unordered_map>

bool LeetCode593::validSquare(vector<int> &p1, vector<int> &p2, vector<int> &p3, vector<int> &p4) {
    if (p1[0] == p2[0] && p1[1] == p2[1] || p1[0] == p3[0] && p1[1] == p3[1] || p1[0] == p4[0] && p1[1] == p4[1] || p2[0] == p3[0] && p2[1] == p3[1] || p2[0] == p4[0] && p2[1] == p4[1] || p3[0] == p4[0] && p3[1] == p4[1]) {
        return false;
    }
    unordered_map<int, int> distanceCount;
    unordered_map<int, vector<pair<int, int>>> records;
    int distancep1p2 = distance(p1, p2);
    int distancep1p3 = distance(p1, p3);
    int distancep1p4 = distance(p1, p4);
    int distancep2p3 = distance(p2, p3);
    int distancep2p4 = distance(p2, p4);
    int distancep3p4 = distance(p3, p4);
    if (distanceCount.count(distancep1p2)) {
        distanceCount[distancep1p2]++;
    } else {
        distanceCount.insert(unordered_map<int, int>::value_type(distancep1p2, 1));
    }
    if (distanceCount.count(distancep1p3)) {
        distanceCount[distancep1p3]++;
    } else {
        distanceCount.insert(unordered_map<int, int>::value_type(distancep1p3, 1));
    }
    if (distanceCount.count(distancep1p4)) {
        distanceCount[distancep1p4]++;
    } else {
        distanceCount.insert(unordered_map<int, int>::value_type(distancep1p4, 1));
    }
    if (distanceCount.count(distancep2p3)) {
        distanceCount[distancep2p3]++;
    } else {
        distanceCount.insert(unordered_map<int, int>::value_type(distancep2p3, 1));
    }
    if (distanceCount.count(distancep2p4)) {
        distanceCount[distancep2p4]++;
    } else {
        distanceCount.insert(unordered_map<int, int>::value_type(distancep2p4, 1));
    }
    if (distanceCount.count(distancep3p4)) {
        distanceCount[distancep3p4]++;
    } else {
        distanceCount.insert(unordered_map<int, int>::value_type(distancep3p4, 1));
    }
    records[distancep1p2].emplace_back(1, 2);
    records[distancep1p3].emplace_back(1, 3);
    records[distancep1p4].emplace_back(1, 4);
    records[distancep2p3].emplace_back(2, 3);
    records[distancep2p4].emplace_back(2, 4);
    records[distancep3p4].emplace_back(3, 4);
    auto it = distanceCount.begin();
    int edgeDistance;
    while (it != distanceCount.end()) {
        if (it->second == 4) {
            edgeDistance = it->first;
            break;
        }
        it++;
    }
    if (it == distanceCount.end()) {
        return false;
    }
    auto edges = records[edgeDistance];
    int zeroAngle = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            int index1 = edges[i].first;
            int index2 = edges[i].second;
            vector<int> point1, point2;
            switch (index1) {
                case 1:
                    point1 = p1;
                    break;
                case 2:
                    point1 = p2;
                    break;
                case 3:
                    point1 = p3;
                    break;
                case 4:
                    point1 = p4;
                    break;
            }
            switch (index2) {
                case 1:
                    point2 = p1;
                    break;
                case 2:
                    point2 = p2;
                    break;
                case 3:
                    point2 = p3;
                    break;
                case 4:
                    point2 = p4;
                    break;
            }
            vector<int> vec1;
            vec1.emplace_back(point2[0] - point1[0]);
            vec1.emplace_back(point2[1] - point1[1]);
            int index3 = edges[j].first;
            int index4 = edges[j].second;
            vector<int> point3, point4;
            switch (index3) {
                case 1:
                    point3 = p1;
                    break;
                case 2:
                    point3 = p2;
                    break;
                case 3:
                    point3 = p3;
                    break;
                case 4:
                    point3 = p4;
                    break;
            }
            switch (index4) {
                case 1:
                    point4 = p1;
                    break;
                case 2:
                    point4 = p2;
                    break;
                case 3:
                    point4 = p3;
                    break;
                case 4:
                    point4 = p4;
                    break;
            }
            vector<int> vec2;
            vec2.emplace_back(point4[0] - point3[0]);
            vec2.emplace_back(point4[1] - point3[1]);
            int dotVal = dot(vec1, vec2);
            if (dotVal == 0) {
                zeroAngle++;
            }
        }
    }
    if (zeroAngle == 4) {
        return true;
    } else {
        return false;
    }
}

int LeetCode593::distance(vector<int> &p1, vector<int> &p2) {
    int dx = p1[0] - p2[0];
    int dy = p1[1] - p2[1];
    return dx * dx + dy * dy;
}

int LeetCode593::dot(vector<int> &vec1, vector<int> &vec2) {
    return vec1[0] * vec2[0] + vec1[1] * vec2[1];
}

