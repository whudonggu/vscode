#include<vector>
#include<iostream>
using namespace std;
class Solution{
    public:
void FIndNumsAppearOnce(vector<int> &T ,int *num1,int *num2)
{
    if(T.size()<2)
        return;
    int resultExclusiveOR = 0;
    for (vector<int>::iterator it1 = T.begin(); it1 != T.end();it1++)
        resultExclusiveOR ^= *it1;

    unsigned int indexOf1 = findfirstbitsis1(resultExclusiveOR);

    *num1 = *num2 = 0;

    for (vector<int>::iterator it1 = T.begin();it1 != T.end();it1++)
    {
        if(isbit1(*it1,indexOf1))
            *num1 ^= *it1;
        else
            *num2 ^= *it1;
    }
}

unsigned int findfirstbitsis1(int num)
{
    int indexbit = 0;
    while((num&1)==0&&(indexbit<8*sizeof(int)))
    {
        num = num >> 1;
        ++indexbit;

    }
    return indexbit;
}

bool isbit1(int num,unsigned int indexbit)
{
    num = num >> indexbit;
    return (num & 1);
}
};

int main()
{
    Solution yb;
    vector<int> T = {1, 2, 2, 1, 3, 4, 4, 5, 3, 6, 6, 7,7,9};
    int num1, num2;
    yb.FIndNumsAppearOnce(T, &num1, &num2);
    cout << num1 << " " << num2 << endl;
    return 0;
}