#include<iostream>
#include<cstdlib>
#include<vector>

using namespace std;

int main()
{
    vector<int> table = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    //cout << table[1];
    int n;
    cin >> n;
    vector<int> res(n + 1, 0);
    for (int i = 1; i <=n;i++)
    {
        int max = -1;
        for (int j = 1; j <= i;j++)
        {
            if(max<table[j]+res[i-j])
                max = table[j] + res[i - j];
        }
        res[i] = max;
    }
    cout << res[n] << " ";
    cout << endl;
    return 0;
}