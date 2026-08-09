class Solution {
public:
    int n;
    int dp[2][100][100];
    int solve(vector<int>& piles, int alice, int i, int m)
    {
        if(i >= n) return 0;
        if(dp[alice][i][m] != -1) return dp[alice][i][m];

        int result = (alice == 1)? -1 : INT_MAX;
        int stones = 0;

        for(int x = 1; x <= min(2*m,n-i); x++)
        {
            stones += piles[i+x-1];
            if(alice == 1) 
                result = max(result, stones + solve(piles,0,i+x,max(m,x))); 
            else
                result = min(result, solve(piles,1,i+x,max(m,x)));
        }

        return dp[alice][i][m] = result;
    }
    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        memset(dp,-1,sizeof(dp));
        return solve(piles,1,0,1);
    }
};