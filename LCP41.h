//
// Created by 陆泽辉 on 2023/6/21.
//

#ifndef LEETCODE_LCP41_H
#define LEETCODE_LCP41_H

#include <string>
#include <vector>

using namespace std;

class LCP41 {
public:
    int flipChess(vector<string>& chessboard);

private:
    bool judge(const vector<string>& chessboard, int x, int y, int dx, int dy);
    int bfs(vector<string> chessboard, int px, int py);
};


#endif //LEETCODE_LCP41_H
