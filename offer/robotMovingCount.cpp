#include<iostream>

uisng namespace std;

int RobotMovingCount(int stop,int rows,int cols)
{
    if(stop<0||rows<0||cols<0)
        return 0;
    bool *visited = new bool[rows * cols];
    for (int i = 0; i < rows*cols; i++)
    {
        visited[i] = false;
    }

    int count = RobotMovingCountCore(stop, rows, cols, 0, 0, visited);

    return count;
}

int RobotMovingCountCore(int stop,int rows,int cols,int row,int col,bool *visited)
{
    int count = 0;
    if(check(stop,rows,cols,row,col,visited))
    {
        visited[row * cols + col] = true;
        count = 1 + RobotMovingCountCore(stop, rows, cols, row + 1, col, visited) +
                RobotMovingCountCore(stop, rows, cols, row, col + 1, visited) +
                RobotMovingCountCore(stop, rows, cols, row - 1, col, visited) +
                RobotMovingCountCore(stop, rows, cols, row, col - 1, visited);
    }

    return count;
}

bool check(int stop,int rows,int cols,int row,int col,bool *visited)
{
    if(row>=0&&col>=0&&col<=cols&&row<=rows&&getDigit(row)+getDigit(col)<=stop&&!visited[row*cols+col])
        return true;
    return false;
}

int getDigit(int num)
{
    int sum = 0;
    if(sum>0)
    {
        sum += num % 10;
        num = num / 10;
    }
    return sum;
}