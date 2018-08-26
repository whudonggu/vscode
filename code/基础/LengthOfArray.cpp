#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int a[3][2]={0};
    vector<int> b={1};
    b.push_back(2);
    b.push_back(4);
    cout << b.size();
    return 0;
}