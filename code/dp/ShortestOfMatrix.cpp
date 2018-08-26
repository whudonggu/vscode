#include <iostream>
#include <algorithm>
using namespace std;

int dp[4][4] = {};

int main()
{
    int a[4][4] = {1, 3, 5, 9, 8, 1, 3, 4, 5, 0, 6, 1, 8, 8, 4, 0};
    for (int i = 0; i < 4;++i)
    {
        for (int j = 0; j < 4;++j)
        {
            if(i==0&&j==0)
            {
                dp[i][j] = a[i][j];
            }
            else if(i==0&&j!=0)
            {
                dp[i][j] = a[i][j] + dp[i][j - 1];
            }
            else if(i!=0&&j==0)
            {
                dp[i][j] = a[i][j] + dp[i - 1][j];
            }
            else
            {
                dp[i][j] = a[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
            }
            
        }
    }

    cout << "走到位置";
    cout << dp[3][3];

    return 0;
}