#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:

    int threeSumClosest(vector<int>& nums, int target) {
        int length=nums.size();
        sort(nums.begin(), nums.end());
        int left = 0,right=length-1;
        int ans = nums[0] + nums[1] + nums[length - 1];
        while(left<length)
        {
            int a = nums[left], j = left + 1;
            right = length - 1;
            while(j<right)
            {
                int b = nums[j];
                int c = nums[right];
                int temp = a + b + c;
                if(abs(temp-target)<abs(ans-target))
                    ans = temp;
                if(ans==target)
                    return ans;
                if(temp<target)
                {
                    while(nums[j]==b)
                        ++j;
                }
                if(temp>target)
                {
                    while(nums[right]==c)
                        --right;
                }
                cout << left << " " << j << " " << right << '\n';
            }
            while(nums[left]==a&&left<length)
                ++left;
        }
        return ans;
    }
};

int main()
{
    Solution yb;
    vector<int> test = {1,2,4,8,16,32,64,128};
    cout << yb.threeSumClosest(test, 82);
    return 0;
}