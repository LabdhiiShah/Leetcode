class Solution {
public:
    int t[23][23];
    int solve(int i, int j, vector<int>& nums)
    {
        if(i > j) return 0;
        if(i == j) return nums[i];

        if(t[i][j] != -1) return t[i][j];

        int take_i = nums[i] + min(solve(i+2,j,nums), solve(i+1,j-1,nums));
        int take_j = nums[j] + min(solve(i,j-2,nums), solve(i+1,j-1,nums));
        return t[i][j] = max(take_i, take_j);
    }

    bool predictTheWinner(vector<int>& nums) {
        memset(t,-1,sizeof(t));
        int total = 0;
        for(auto &n: nums)
            total += n;
        int player1 = solve(0,nums.size()-1,nums);
        int player2 = total - player1;
        return (player1 >= player2);
    }
};                              