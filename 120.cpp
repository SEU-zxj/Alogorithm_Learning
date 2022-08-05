class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, 9999999));
        //初始化
        dp[0][0] = triangle[0][0];
        for(int i = 1 ; i < n ; i++)
        {
            dp[i][0] = dp[i-1][0] + triangle[i][0];
            dp[i][i] = dp[i-1][i-1] + triangle[i][i];
        }
        //开始dp
        for(int i = 2 ; i < n ; i++)
        {
            for(int j = 1 ; j < i ; j++)
            {
                dp[i][j] = min(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j];
            }
        }
        int ans = INT_MAX;
        for(int i = 0 ; i < n ; i++)
        {
            ans = min(ans, dp[n-1][i]);
        }
        return ans;
    }
};