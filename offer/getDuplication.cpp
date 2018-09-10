#include<iostream>
using namespace std;

//不能保证找出所有重复的数字，此算法在区间为[1,2]时，若所含数字为两个2，count也为2，不能判断出2为重复数字
int countRange(const int* numbers,int length,int start,int end)
{
    if(numbers==NULL||length<=0)
        return 0;
    int count = 0;
    for (int i = 0; i < length;i++)
    {
        if(numbers[i]>=start&&numbers[i]<=end)
            ++count;
    }
    return count;
}

int getDuplication(const int *numbers,int length)
{
    if(numbers==NULL||length<=0)
        return -1;
    int start = 1; //开始的范围是在1---length-1之间的所有数的count
    int end = length - 1;
    while(end>=start)
    {
        int middle = ((end - start) >> 1) + start;  //右移一位等于除以2
        int count = countRange(numbers, length, start, middle);
        if(end==start)
        {
            if(count>1)         //大小区间为1如果数目大于1，一定存在重复数
                return start;   //如果找出一个重复的就return，如果有多个的话应该志记这一个 再查找其他的
            else
                break;
        }
        if(count>(middle-start+1))      //典型的二分思路
            end = middle;
        else
            start = middle + 1;
    }
}


int main()
{
    int a[] = {2, 3, 5, 4, 3, 2, 6, 7};
    int b = getDuplication(a, 8);
    cout << b << endl;
    return 0;
}