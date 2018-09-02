#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int candy(vector<int> &ratings) {
        int res = 0;
        if(ratings.size()==1)
            return res = 1;
        int n = ratings.size();
        vector<int> candies(n, 1);
        for (int i = 1; i < n;i++)
            candies[i] = ratings[i] > ratings[i - 1] ? candies[i-1] + 1 : candies[i];
        for (int i = n - 2; i >= 0;i--)
        {
            if(ratings[i] > ratings[i + 1])
            {
                    if (candies[i]>candies[i+1])
                        ;
                    else
                        candies[i] = candies[i + 1] + 1;
            }
        }
        for (int i = 0; i < n;i++)
            res = res + candies[i];
        return res;
    }
};