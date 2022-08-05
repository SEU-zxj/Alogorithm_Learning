class Solution {
public:
    int rob(vector<int>& nums) 
    {
        if(nums.size() == 1)
        {
            return nums[0];
        }
        int first = nums[0];
        int second = max(nums[0], nums[1]);
        for(int i = 3 ; i <= nums.size() ; i++)
        {
            int temp = second;
            second = max(second, nums[i-1]+first);
            first = temp;
        }
        return second;
    }
};