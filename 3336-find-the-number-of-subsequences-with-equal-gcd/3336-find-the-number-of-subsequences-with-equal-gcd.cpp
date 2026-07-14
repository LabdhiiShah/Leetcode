class Solution {
public:
    int MOD = 1e9 + 7;
    int dp[201][201][201];
    int gcd(int a, int b)
    {
        while(b != 0)
        {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    int solve(vector<int> &nums, int i, int first, int second)
    {
        if(i == nums.size())
        {
            bool bothNonEmpty = (first != 0 && second != 0);
            bool gcdMatches = (first == second);

            return bothNonEmpty && gcdMatches;
        }

        if(dp[i][first][second] != -1) return dp[i][first][second];

        int skip = solve(nums,i+1,first,second);
        int take1 = solve(nums,i+1,gcd(first,nums[i]),second);
        int take2 = solve(nums,i+1,first,gcd(second,nums[i]));

        return dp[i][first][second] = (0LL + skip + take1 + take2) % MOD;
    }

    int subsequencePairCount(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(nums,0,0,0);
    }
};