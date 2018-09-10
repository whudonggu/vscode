#include<iostream>
using namespace std;

int main()
{
    char str1[] = "hello world";
    char str2[] = "hello world";

    char *str3 = "hello world";
    char *str4 = "hello world";

    if(str1==str2)
        cout << "str1 and str2 are same.\n";
    else
        cout << "str1 and str2 are not same.\n";

    if(str3==str4)
        cout << "str3 and str4 are same.\n";
        else
            cout << "str3 and str4 are not same.";

        return 0;
}