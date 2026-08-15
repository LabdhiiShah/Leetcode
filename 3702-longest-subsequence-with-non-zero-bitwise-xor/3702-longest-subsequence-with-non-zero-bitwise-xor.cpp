class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int len = nums.size();
        int result = 0;
        bool allZero = true;
        for(auto &n: nums)
        {
            result = result ^ n;
            if(n != 0) allZero = false;
        }

        if(allZero)
            return 0;
        return result == 0? len-1 : len;
    }
};