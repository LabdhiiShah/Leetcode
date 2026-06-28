class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();
        vector<int> freq(n+1,0);

        for(auto& a: arr)
            freq[min(a,n)]++;

        int ans = 0;
        for(int i = 1; i < freq.size(); i++)
            ans = min(ans+freq[i], i);

        return ans;
    }
};