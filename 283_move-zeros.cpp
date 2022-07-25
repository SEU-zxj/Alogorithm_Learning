class Solution {
public:
    void moveZeroes(vector<int>& nums) 
    {
        int n = nums.size();
        //p1 will be used to go throuth, while p2 will be used to swap
        int p1 = 0;
        int p2 = 0;
        while(p1 != n)
        {
            if(nums[p1] == 0)
            {
                p1++;
            }
            else
            {
                swap(nums[p1++], nums[p2++]);
            }
        }
        while(p2 != n)
        {
            nums[p2++] = 0;
        }
    }
};