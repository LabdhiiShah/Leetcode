class Solution {
public:
    int p[501][501];
    int solve(int i, int j, vector<int> &piles)
    {
        if(i > j) return 0;
        if(p[i][j] != -1) return p[i][j];
        int take_i = piles[i] + min(solve(i+2,j,piles), solve(i+1,j-1,piles));
        int take_j = piles[j] + min(solve(i,j-2,piles), solve(i+1,j-1,piles));
        return p[i][j] =  max(take_i, take_j);
    }
    bool stoneGame(vector<int>& piles) {
        memset(p,-1,sizeof(p));
        int total = 0;
        for(auto &p: piles)
            total += p;
        int alice = solve(0,piles.size()-1,piles);
        int bob = total - alice;
        return alice > bob;
    }
};