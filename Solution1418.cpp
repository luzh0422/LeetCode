//
// Created by luzh on 2021/7/6.
//

#include "Solution1418.h"

#include <map>

/*编写类或者结构体按key升序或者降序*/
struct Flag {
    bool operator() (const string& v1, const string& v2) const {
        return stoi(v1) < stoi(v2);
    }
};

vector<vector<string>> Solution1418::displayTable(vector<vector<string>> &orders) {
    typedef map<string, map<string, int>, Flag> TableMap;
    typedef map<string, int, less<string>> FoodMap;
    TableMap m;
    FoodMap foodMap;
    for (auto& order : orders) {
        string name = order[0];
        string table = order[1];
        string food = order[2];
        if (m.count(table)) {
            auto& tableM = m[table];
            if (tableM.count(food)) {
                tableM[food]++;
            } else {
                tableM[food] = 1;
            }
        } else {
            m.insert(TableMap::value_type(table, {}));
            auto& tableM = m[table];
            tableM[food] = 1;
        }
        if (!foodMap.count(food)) {
            foodMap[food] = 1;
        }
    }
    int row = m.size();
    int column = foodMap.size();
    vector<vector<string>> ret(m.size() + 1, vector<string>(foodMap.size() + 1, "0"));
    /**
     * 初始化答案第一行；
     */
    ret[0][0] = "Table";
    vector<string> foods = {};
    int columnCount = 1;
    for (auto it = foodMap.begin(); it != foodMap.end(); it++) {
        foods.push_back(it->first);
        it->second = columnCount;
        columnCount += 1;
    }
    for (int i = 0; i < foods.size(); i++) {
        ret[0][i + 1] = foods[i];
    }
    /**
     * 赋值每一行；
     */
    int rowCount = 1;
    for (auto it = m.begin(); it != m.end(); it++) {
        string tableName = it->first;
        ret[rowCount][0] = tableName;
        auto& foodList = it->second;
        for (auto jt = foodList.begin(); jt != foodList.end(); jt++) {
            string foodName = jt->first;
            int foodCount = jt->second;
            int column = foodMap[foodName];
            ret[rowCount][column] = to_string(foodCount);
        }
        rowCount += 1;
    }
    return ret;
}
