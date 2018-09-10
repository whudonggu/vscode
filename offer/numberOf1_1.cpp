#include<iostream>

using namespace std;

int numberof1_1(int n)
{
    int count = 0;
    unsigned int flag = 1;
    while(flag)
    {
        if(n&flag)
            count++;

        flag = flag << 1;
    }
    cout << count<<'\n';
    return count;
}

int numberof1_2(int n)
{
    int count = 0;

    while (n)
    {
        ++count;
        n = (n - 1) & n;
    }

    cout << count<<'\n';

    return count;
}

int main()
{
    numberof1_1(0x80000000);
    numberof1_2(0x80000000);
    numberof1_1(0x7fffffff);
    numberof1_2(0x7fffffff);
    numberof1_1(0xffffffff);
    numberof1_2(0xffffffff);
    return 0;
}