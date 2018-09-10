#include<iostream>
using namespace std;




class Animal
{
private:
    /* data */
  int v1;

protected:
  int v2;

public:
    
    Animal(/* args */);
    ~
    Animal();
          void eat()
      {
          cout << "Animal eat\n";
      }
    void setValue(int x)
    {
        v1 = x;
    }
    void PrintValue()
    {
        cout << v1;
    }
};


Animal::
Animal(/* args */)
{
}


Animal::~
Animal()
{
}


int main()
{
    Animal a;
    a.eat();
    a.setValue(2);
    a.PrintValue();
    a.v2 = 3;
    return 0;
}