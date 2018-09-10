#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;


bool Increment(char *number)
{
    bool isOverflow = false;
    int nTakeover = 0;
    int nlength = strlen(number);

    for (int i = nlength-1; i >=0; i--)
    {
        int nSum = number[i] - '0' + nTakeover;
        if(i==nlength-1)
            nSum++;

            if(nSum>=10)
            {
                if(i==0)
                {
                    isOverflow = true;
                }
                else
                {
                    nSum -= 10;
                    nTakeover = 1;
                    number[i] = '0' + nSum;
                }
            }
            else
            {
                number[i] = '0' + nSum;
                break;
            }
    }
    return isOverflow;
}

void PrintNumber(char* number)
{
    bool isBeginning0 = true;
    int nlength = strlen(number);

    for (int i = 0; i < nlength; i++)
    {
        if(isBeginning0&&number[i]!='0')
            isBeginning0 = false;

        if(!isBeginning0)
            {
                cout << number[i];
            }
    }
    cout << '\t';
}

void Print1ToMaxOfNDigits(int n)
{
    if(n<0)
        return;

    char *number = new char[n+1];
    memset(number, '0', n);
    number[n] = '\0';
    int length = strlen(number);
    strcpy(number,"199");
    while(!Increment(number))
    {
        PrintNumber(number);
    }

    delete[] number;
}
int main(){
    Print1ToMaxOfNDigits(3);
    return 0;
}