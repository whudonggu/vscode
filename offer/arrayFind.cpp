#include<iostream>

using namespace std;

bool Find(int* matirix,int rows,int columns, int number)
{
    if(matirix==NULL)
        return false;
    bool res = false;

    if(matirix!=NULL&&rows>0&&columns>0)
    {
        int row = 0;
        int column = columns - 1;

        while(row<rows&&column>=0)
        {
            if(matirix[row*columns+column]==number)
            {
                found = true;
                break;
            }
            else if (matirix[row*columns+column]>number)
            {
                --column;
            }
            else
                ++row;
        }
    }
    return found;
}