class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> freq(51, 0);
        vector<int> windows(51, 0);

        for (int i = 0; i < k; i++) {
            freq[nums[i]]++;
        }

        for (int x = 0; x <= 50; x++) {
            if (freq[x] > 0)
                windows[x]++;
        }

        for (int i = k; i < n; i++) {
            freq[nums[i - k]]--;
            freq[nums[i]]++;

            for (int x = 0; x <= 50; x++) {
                if (freq[x] > 0)
                    windows[x]++;
            }
        }

        int ans = -1;
        for (int x = 0; x <= 50; x++) {
            if (windows[x] == 1)
                ans = x;
        }

        return ans;
    }
};