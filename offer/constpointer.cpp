#include<iostream>
using namespace std;
int main()
{
    //常量指针
    int a=1,b=2;
    const int *p1 = &a;
    a = 300;
    cout << *p1 << endl;
    //*p1 = 56;
    p1 = &b;


    //指针常量
    int *const p2 = &a;
    a = 500;
    *p2 = 400;
    //p2 = &b;

    //指向常量的常量指针 
    const int c = 1000;
    const int *const p3 = &c;
    //*p3 = 1;
    //p3 = &b;
    c = 5000;

    return 0;
}