#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) 
    {
        int left = 0;
        int right = nums.size() - 1;
        int mid = (left + right)/2;

        //special cases
        if(nums[0] > target)
        {
            return 0;
        }
        if(nums[right] < target)
        {
            return right + 1;
        }

        //if left == right, break out
        while(left < right)
        {
            if(nums[mid] == target)
            {
                return mid;
            }
            else
                {
                if(nums[mid] < target)
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }
            mid = (left + right)/2;
        }

        if(nums[mid] >= target)
        {
            return mid;
        }
        else
        {
            return mid + 1;
        }
    }
};