//decrease the space complexity
class Solution {
public:
    void ReverseArray(vector<int>& nums, int start, int end)
    {
        //if start == end, there is no need to reverse...
        while(start < end)
        {
            swap(nums[start], nums[end]);
            start++;
            end--;
        }
    }
    void rotate(vector<int>& nums, int k) 
    {
        int n = nums.size();
        k %= n;
        ReverseArray(nums, 0, n-1);
        ReverseArray(nums, 0, k-1);
        ReverseArray(nums, k, n-1);
    }
};