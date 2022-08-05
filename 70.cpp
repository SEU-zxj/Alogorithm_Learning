#include <iostream>
using namespace std;
class Solution 
{
public:
    Solution()
    {
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3 ; i < 46 ;i++)
        {
            dp[i] = dp[i-1] + dp[i-2];
        }
    }
    int climbStairs(int n) 
    {
        return dp[n];
    }
private:
    int dp[46] = {};
};
int main()
{
    Solution test;
    cout << test.climbStairs(3);
    return 0;
}