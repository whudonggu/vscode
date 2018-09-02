#include<iostream>
using namespace std;

class Solution {
public:
    int minCut(string s) {
        int len = s.length();
        if(len<2)
            return 0;
        int p[len][len];
        for (int i = 0; i < len;i++)
        {
            for (int j=i; j < len; j++)
            {
                p[i][j] = isPalindrome(s.substr(i, j - i + 1));
            }
        }
        int dp[len];
        for (int i = len - 1; i >= 0;i--)
        {
            for (int j = 0; j < i;j++)
            {
                if(p[j][i])
                    
            }
        }
    }
    int isPalindrome(string s)
    {
        if(s == string(s.rbegin(), s.rend()))
            return 1;
        else
            return 0;
    }
};