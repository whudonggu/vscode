#include<iostream>
#include<string>
#include<vector>

using namespace std;

string Mult(string str1,string str2)
{
    
    int length1 = str1.size(), length2 = str2.size();
    vector<string> tes(length2);
    int len = length1 + length2 + 1;
    for (int i = length2 - 1; i >= 0;i--)
    {
        string tes2 = (char)malloc(sizeof(char) * len);
        for (int j = length1 - 1; j >= 0;j--)
        {
            //string tes2 = (char)malloc(sizeof(char) * len);
            tes[len - 1] = (str1[j] - '0') * (str[i] - '0')*pow(10,(length2-1-i)) + '0';
        }
        tes.push_back(tes2);
    }
    string strres=(char)malloc(sizeof(char) * len);
    memset(strres, '0', len);
    //strres[len-1]='\0'
    for (int i = 0; i < tes.size();i++)
    {
        for (int j = 0; j < len;j++)
        {
            strres=add(strres+tes[i])
        }
    }
}

int main()
{
    string str1, str2;
    cin >> str1 >> str2;
    if(str1.size()==0||str2.size()==0)
        return 0;

    string res = Mult(str1, str2);
    cout << res;
}