#include<iostream>
using namespace std;

class Solution {
public:
    int singleNumber(int A[], int n) {
        int res = A[0];
        if(n==1)
            return res;
        for (int i = 1; i < n;i++)
        {
            res = res ^ A[i];
        }
        return res;
    }
};

int main(){
    Solution yb;
    int A[7] = {2, 2, 2, 3, 3, 3, 6};
    int a = yb.singleNumber(A, 7);
    return 0;
}