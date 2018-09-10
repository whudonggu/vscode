#include <iostream>

using namespace std;

int Min(int nums[],int length)
{
    int min = nums[0];
    for (int i = 1; i < length - 1; i++)
    {
        if(nums[i]<=min)
            min = nums[i];
    }
    return min;
}

int MinInSpinArray(int nums[],int length)
{
    if(nums==NULL||length<=0)
        return -1;

    int start = 0, end = length - 1, middle = 0;

    while (nums[start]>=nums[end])
    {
        if(end-start==1)
        {
            middle = end;
            break;
        }
        middle = (start + end) >> 1;

        
        if (nums[middle]==nums[start]&&nums[start]==nums[end]) {
            /* code */
            return Min(nums, length);
        }
        
        if(nums[middle]>=nums[end])
        {
            start = middle;
        }

        if(nums[middle]<=nums[start])
            end = middle;
    }

    return nums[middle];
}

int main()
{
    int nums[1] = {1};
    int a1 = MinInSpinArray(nums, 1);

    return 0;
}