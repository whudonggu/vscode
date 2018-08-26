#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int left_p = 0, length = nums.size(), right_p = length - 1,j;
        while(left_p<length)
        {
            int a = nums[left_p], j = left_p + 1;
            int temp1 = target - a;
            while(j<length)
            {
                int right_p = length - 1,b = nums[j];
                int k = j + 1;
                while(k<right_p)
                {
                int c = nums[k], d = nums[right_p];
                int temp2 = b + c + d;
                vector<int> tempv = {a, b, c, d};
                if(temp2==temp1)
                    res.push_back(tempv);
                if(temp2>temp1)
                    while(nums[right_p]==d&&k<right_p)
                        --right_p;
                if(temp2<temp1)
                    while(nums[k]==c&&k<right_p)
                        ++k;
                }
                while(nums[j]==b&&j<length)
                    ++j;
            }   
            while(nums[left_p]==a&&left_p<length)
                ++left_p;
        }
        return res;
    }
};

int main()
{
    Solution yb;
    vector<int> test = {-1, 0, 1, 2, 0, -2};
    int target = 0;
    vector<vector<int>> result = yb.fourSum(test, target);
    for (int i = 0; i < result.size();i++)
    {
        for (int j = 0; j < 4;j++)
            cout << result[i].at(j);
        cout<<'\n';
    }
    return 0;
}