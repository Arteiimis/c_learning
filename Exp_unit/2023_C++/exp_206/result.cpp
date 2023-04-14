#include "result.h"

void result::inputPlayer()
{
    player temp;
    cout << "请输入运动员数量：" << endl;
    cin >> playerNumber;
    for (int i = 0; i < playerNumber; i++)
    {
        cout << "请输入第" << i + 1 << "个运动员的编号、姓名：";
        cin >> temp.number >> temp.name;
        players.push_back(temp);
    }
    cout << endl;
}

void result::inputScore()
{
    for (int i = 0; i < playerNumber; i++)
    {
        cout << "请输入第" << i + 1 << "个运动员的成绩：" << endl;
        for (int j = 0; j < judgeNumber; j++)
        {
            double temp;
            cout << "第" << j + 1 << "个裁判的成绩：";
            cin >> temp;
            players[i].score.push_back(temp);
        }
    }
    cout << endl;
}

void result::calculateResult()
{
    for (int i = 0; i < playerNumber; i++)
    {
        double sum = 0;
        sort(players[i].score.begin(), players[i].score.end());
        for (int j = 1; j < judgeNumber - 1; j++)
        {
            sum += players[i].score[j];
        }
        players[i].finalResult = sum / (judgeNumber - 2);
    }
}

void result::outputResult()
{
    cout << "运动员编号\t运动员姓名\t最终成绩" << endl;
    for (int i = 0; i < playerNumber; i++)
    {
        cout << players[i].number << "\t\t" << players[i].name << "\t\t" << players[i].finalResult << endl;
    }
}

void result::outputRank()
{
    sort(players.begin(), players.end(), [](player a, player b) { return a.finalResult > b.finalResult; });
    cout << "运动员编号\t运动员姓名\t最终成绩" << endl;
    for (int i = 0; i < playerNumber; i++)
    {
        cout << players[i].number << "\t\t" << players[i].name << "\t\t" << players[i].finalResult << endl;
    }
}