#include<iostream>
#include<vector>
using namespace std;

bool duplicate(int numbers[],int length,vector<int> *duplicate)
{
    if(numbers==NULL||length<=0)
        return false;
    for (int i = 0; i < length; i++)    //判断是否存在元素不在0---n-1之间      
    {
        if(numbers[i]<0||numbers[i]>length-1)
            return false;
    }
    for (int i = 0; i < length; i++)
    {
        while(numbers[i]!=i)
        {
            if(numbers[i]==numbers[numbers[i]])     //在第i个位置的值不为i的情况下，如果第numbers【i】的位置已经存在numbers[i]的值
                {                                   //那么确实存在重复的值
                    duplicate->push_back(numbers[i]);
                    return true;
                }
            
            //
                int temp = numbers[numbers[i]];
                numbers[numbers[i]] = numbers[i];
                numbers[i] = temp;
        }
    }

    return false;
}

int main()
{
    int numbers[] = {2, 3, 1, 0, 2, 5, 3};
    int length = 7;
    vector<int> res;
    if(duplicate(numbers, length, &res))
        cout << res[0] << endl;
    return 0;
}