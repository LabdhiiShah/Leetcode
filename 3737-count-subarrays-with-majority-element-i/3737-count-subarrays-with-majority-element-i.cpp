class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        // if not present in array, return 0;
        // majority means nums.size()/2 
        // needs to be continuous
        int ans = 0, n = nums.size();
        for(int l = 0; l < n; l++)
        {
            int targetCount = 0;
            for(int r = l; r < n; r++)
            {
                if(nums[r] == target)
                    targetCount++;
                int len = r - l + 1;
                if(targetCount > len/2)
                    ans++;
            }
        }
        return ans;
    }
};