class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = 0;
        vector<int> prefix(n+1,0);

        for(int i = 0; i < n; i++)
            prefix[i+1] = prefix[i] + (nums[i] == target? 1:-1);

        for(int l = 0; l < n; l++)
        {
            for(int r = l; r < n; r++)
            {
                if(prefix[r+1] - prefix[l] > 0)
                    ans++;
            }
        }
        return ans;
    }
};