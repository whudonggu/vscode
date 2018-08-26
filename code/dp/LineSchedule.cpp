#include <iostream>
using namespace std;

#define max 1000;
int main()
{
    int s[2][7] = {{0, 7, 9, 3, 4, 8, 4}, {0, 8, 5, 6, 4, 5, 7}};
    int t[2][7] = {{2, 2, 3, 1, 3, 4, 3}, {4, 2, 1, 2, 2, 1, 2}};

    int f[2][7];
    for (int i = 0; i < 2;i++)
        for (int j = 0; j < 7;j++)
            f[i][j] = max;
    int sum;
    for (int site = 6; site >= 0;site--)
    {
        if(site==6)
        {
            f[0][6] = s[0][6] + t[0][6];
            f[1][6] = s[1][6] + t[1][6];
            continue;
        }
        if(site==0)
        {
            if (t[0][0]+f[0][0]<t[0][1]+f[0][1])
            {
                sum = t[0][0] + f[0][0];
            }
            else
            {
                sum = t[0][1] + f[0][1];
            }
            break;
        }
        
        if(s[0][site]+f[0][site+1]<s[0][site]+t[0][site]+f[1][site+1])
            f[0][site]=s[0][site]+f[0][site+1];
        else
            f[0][site]=s[0][site]+t[0][site]+f[1][site+1];
 
        if(s[1][site]+f[1][site+1]<s[1][site]+t[1][site]+f[0][site+1])
            f[1][site]=s[1][site]+f[1][site+1];
        else
            f[1][site]=s[1][site]+t[1][site]+f[0][site+1];
    }
        return 0;
}
