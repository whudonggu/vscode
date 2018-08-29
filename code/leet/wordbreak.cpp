#include<iostream>
#include<unordered_set>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        int len = s.size();
        dp = new vector<bool>[s.size()];
       for (int i = 0; i < len;i++)
        {
            for (int j = i; j < len;j++)
            {
                dp[i].push_back(match(s.substr(i, j - i + 1), dict));
            }
        }
        handleStr(len - 1, s);
        reverse(res.begin(),res.end());
        return res;
    }
    bool match(string str,unordered_set<string> &dict)
    {
        if(dict.count(str))
            return true;
        return false;
    }
    void handleStr(int i,string s)
    {
        if(i==-1)
        {
            string str;
            for (int j = mystring.size() - 1; j >= 0;j--)
            {
                str += mystring[j];
                if(j!=0)
                    str += " ";
            }
            res.push_back(str);
        }
        else
        {
            for (int k = 0; k <= i;k++)
            {
                if(dp[k][i-k]){
                    mystring.push_back(s.substr(k, i-k+1));
                    handleStr(k - 1, s);
                    mystring.pop_back();
                }
            }
        }
    }
    vector<string> res;
    vector<string> mystring;
    vector<bool> *dp;
};

int main()
{
    Solution yb;
    string test = "catsanddog";
    unordered_set<string> dict = {"cat", "cats", "and", "sand", "dog"};
    yb.wordBreak(test, dict);
    return 0;
}
