#include <bits/stdc++.h>
using namespace std;

#define FOOT 8
#define VISITED 4

const int rowsize = 10;
const int colsize = 10;

typedef int mazeType[rowsize][colsize]; 

typedef struct posType
{
    int row;
    int col;
    posType(int _row, int _col) : row(_row), col(_col) {}
};

typedef struct
{
    int ord;
    posType seat;
    int di;
} elemType;

bool mazePath(mazeType maze, posType start, posType end);

bool pass(mazeType maze, posType curpos)
{
    if (maze[curpos.row][curpos.col] == 0)
        return true;
    else
        return false;
}

void footPrint(mazeType maze, posType curpos)
{
    maze[curpos.row][curpos.col] = FOOT;
}

posType nextPos(posType curPos, int di)
{
    switch (curPos.di)
    {
        
    }
}

bool mazePath(mazeType maze, posType start, posType end)
{
    stack<elemType> visited;
    posType curpos = start;
    elemType curstep;
    int curstepnum = 1;

    do
    {
        if (pass(maze, curpos))
        {
            footPrint(maze, curpos);
            curstep.ord = curstepnum++;
            curstep.seat = curpos;
            curstep.di = 1;
            visited.push(curstep);
            if (curpos.row == end.row && curpos.col == end.col)
                return true;
            curpos = nextPos(curpos, curstep.di);
        }
        else
        {
            if (!visited.empty())
            {
                visited.pop();
                while (!visited.empty() && visited.top().di == 4)
                {
                    markPrint(maze, visited.top().seat);
                    visited.pop();
                }
                if (curstep.di < 4)
                {
                    curstep.di++;
                    visited.push(curstep);
                    curpos = nextPos(curstep.seat, curstep.di);
                }
            }
        }
    } while (!visited.empty());
    free(visited);

    return false;
}


int main()
{
    int maze[rowsize][colsize] = 
    {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
        {1, 0, 1, 0, 1, 0, 1, 1, 0, 1},
        {1, 0, 1, 0, 0, 0, 1, 0, 0, 1},
        {1, 0, 1, 1, 1, 1, 1, 0, 1, 1},
        {1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 0, 1, 1, 1, 1, 0, 1},
        {1, 0, 1, 0, 1, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 1, 0, 1, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };

}