class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        int left = 0;
        int len = 1;
        for(int right = 0; right < nums.size(); right++)
        {
            freq[nums[right]]++;

            while(freq[nums[right]] > k)
            {
                freq[nums[left]]--;
                left++;
            }

            len = max(len, right-left+1);
        }
        return len;
    }
};