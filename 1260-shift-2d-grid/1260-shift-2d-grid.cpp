class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<int> nums;

        if(k == 0) return grid; 
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                nums.push_back(grid[i][j]);
            }
        }

        int s = nums.size();
        k %= s;

        auto reverse = [&](int i, int j) {
            while(i < j)
            {
                swap(nums[i],nums[j]);
                i++;
                j--;
            }
        };
        
        reverse(0,s-1);
        reverse(0,k-1);
        reverse(k,s-1);

        for(int i = 0; i < s; i++)
        {
            int row = i / n, col = i % n;
            grid[row][col] = nums[i];
        }

        return grid;
    }
};