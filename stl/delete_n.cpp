#include<vector>
#include<iostream>
using namespace std;

void detele_n(vector<int> &T,int n)
{
    if(T.size()==0)
        return;
    vector<int>::iterator ivect = T.begin();
    for (; ivect != T.end();ivect++)
    {
        if(*ivect==n)
        {
            erase(*ivect);
            ivect--;
        }

    }
}

int main()
{
    vector<int> T = {1, 1, 1, 2, 2, 2, 3, 3, 2, 2, 1};
    detele_n(T, 2);
    for (vector<int>::iterator ivect = T.begin(); ivect != T.end();ivect++)
        cout << *ivect << endl;

    return 0;
}