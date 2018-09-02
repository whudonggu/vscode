#include<vector>
#include<list>
#include<deque>
#include<algorithm>
#include<iostream>
using namespace std;

int main()
{
    const int arraysize = 7;
    int ia[arraysize] = {0, 1, 2, 3, 4, 5, 6};

    vector<int> ivet(ia, ia + arraysize);
    list<int> ilist(ia, ia + arraysize);
    deque<int> ideque(ia, ia + arraysize);

    vector<int>::iterator it1 = find(ivet.begin(), ivet.end(), 4);
    if(it1==ivet.end())
        cout << "4 not find" << endl;
    else
        cout << "4 find" << *it1 << endl;
    
    list<int>::iterator it2 = find(ilist.begin(), ilist.end(), 6);
    if(it2==ilist.end())
        cout << "6 not find" << endl;
    else
        cout << "6 find" << *it2 << endl;

    deque<int>::iterator it3 = find(ideque.begin(), ideque.end(), 8);
    if(it3==ideque.end())
        cout << "8 not find" << endl;
    else
        cout << "8 find" << *it3 << endl;
    return 0;
}