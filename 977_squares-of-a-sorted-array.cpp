class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) 
    {
        //double pointer
        vector<int> result(nums.size());
        int left = 0;
        int right = nums.size() - 1;
        int num = result.size() - 1;
        while(left != right)
        {
            int a = nums[left] * nums[left];
            int b = nums[right] * nums[right];
            if(a >= b)
            {
                result[num] = a;
                left++;
                num--;
            }
            else
            {
                result[num] = b;
                right--;
                num--;                
            }
        }

        result[num] = nums[left] * nums[left];
        return result;
    }
};