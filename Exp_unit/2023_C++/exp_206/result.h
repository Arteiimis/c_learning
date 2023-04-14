#ifndef RESULT_H
#define RESULT_H

#include <bits/stdc++.h>
#define UMPIRE 5                // 裁判数量
using namespace std;

class result
{
private:
    struct player
    {
        int number;             //运动员编号             .
        string name;            //运动员姓名
        vector<double> score;   //运动员成绩
        double finalResult;     //运动员最终成绩

        player() : number(0), name(""), finalResult(0) {}
    };

    int playerNumber;           //运动员数量
    int judgeNumber = UMPIRE;   //裁判数量
    vector<player> players;     //运动员信息

public:
    result(): playerNumber(0) {}
    result(int p, int j) : playerNumber(p), judgeNumber(j) {}
    void inputPlayer();
    void inputScore();
    void calculateResult();
    void outputResult();
    void outputRank();
};

#endif