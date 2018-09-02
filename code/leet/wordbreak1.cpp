#include<iostream>
#include<unordered_set>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
//错误做法，还是老实动态规划

class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        unsigned long j;
        for (unsigned long i = 0; i < s.size();)
        {
            for (j = i; j < s.size();j++)
            {
                if(match(s.substr(i, j - i + 1), dict))
                    {
                        i=j+1;
                        break;
                    }
                    else if (j==s.size()-1)
                    {
                        return false;
                    }
            }
            if(i==s.size())
                return true;
        }
        return false;
    }
        bool match(string str,unordered_set<string> &dict)
    {
        if(dict.count(str))
            return true;
        return false;
    }
};

int main()
{
    Solution yb;
    string test = "aaaaaaa";
    unordered_set<string> dict = {"aaaa", "aaa", "and", "sand", "dog"};
    yb.wordBreak(test, dict);
    return 0;
}