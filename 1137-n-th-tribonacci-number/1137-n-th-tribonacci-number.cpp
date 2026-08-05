class Solution {
public:
    int dp[38];
    int solve(int i)
    {
        if(i < 0) return 0;
        if(i == 1 || i == 2) return dp[i] = 1;
        
        if(dp[i] != -1) return dp[i];
        return dp[i] = solve(i-1) + solve(i-2) + solve(i-3);
    }
    int tribonacci(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(n);
    }
};