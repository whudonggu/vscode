#include<iostream>
#include<vector>
using namespace std;
class Solution{
    public:
vector<int> solution(vector<int> &T) {
    // write your code in C++14 (g++ 6.2.0)
    unsigned int len=T.size();
    vector<int> res(len,0);
    for(unsigned i=0;i<len;i++)
    {
        int m=T[i],k=i,dist=0;
        while(m!=k)
        {
            k=m;
            m=T[m];
            dist++;
        }
        res[dist]++;
    }
    return res;
 }
};

int main()
{
    Solution yb;
    vector<int> T = {9, 1, 4, 9, 0, 4, 8, 9, 0, 1};
    vector<int> m = yb.solution(T);
    return 0;
}