class Solution {
public:
    int dp[101];
    int solve(int i, vector<int> &nums)
    {
        if(i > nums.size()-1) return 0;
        if(i == nums.size()-1) return dp[i] = nums[i];
        if(dp[i] != -1) return dp[i];
        return dp[i] = nums[i] + max(solve(i+2,nums), solve(i+3,nums));
    }

    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int zero = solve(0,nums);
        int one = solve(1,nums);
        return max(zero,one);
    }
};