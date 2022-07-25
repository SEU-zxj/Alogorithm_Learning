#include <iostream>
#include <vector>
using namespace std;

//decrease the space complexity
class Solution {
public:
    void rotate(vector<int>& nums, int k) 
    {
        int n = nums.size();
        k = k % n;
        if(k == 0)
        {
            return;
        }
        //numbers that need to go through all elements in the array
        int cnt = gcd(k, n);
        for(int i = 0 ; i < cnt ; i++)
        {
            int x = (i + k)%n;
            int temp = nums[i];
            //not go through all elements of nums[i]
            while(x != i)
            {
                swap(nums[x], temp);
                x = (x + k) % n;
            }
            //now x == i, do last swap
            swap(nums[x], temp);
        }
    }
};