#include<iostream>

using namespace std;

class A{
    public:
        void fun(){
            cout << 'A';
        }
};

class B:public A
{
    public:
    void fun(int x){
        cout << 'B';
    }
};

int main()
{
    A a;
    B b;
    a.fun();
    b.fun();
    b.A::fun();
    b.fun(10);

    return 0;
}