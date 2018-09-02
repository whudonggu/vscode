#include<iostream>
using namespace std;

class Solution {
public:
    int singleNumber(int A[], int n) {
        if(A==NULL||n<=0)
            throw new exception("Invalid input");
        int bitsum[32] = {0};
        for (int i = 0; i < n;i++)
        {
            int bitmask = 1;
            for(int j = 31; j >= 0; j--)
            {
                int bit = A[i] & bitmask;
                if(bit!=0)
                    bitsum[j] += 1;
                bitmask = bitmask << 1;
            }
            
        }
        int res = 0;
        for (int i = 0; i < 32;i++)
        {
            res = res << 1;
            res += bitsum[i] % 3;
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