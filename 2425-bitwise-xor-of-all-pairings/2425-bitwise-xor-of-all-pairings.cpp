class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int ans = 0;

        if(n % 2 == 0 && m % 2 == 0)
            ans = 0;
        else if(n % 2 == 0 && m % 2 != 0)
        {
            for(auto &n: nums1)
                ans = ans^n;
        } 
        else if(n % 2 != 0 && m % 2 == 0)
        {
            for(auto &n: nums2)
                ans = ans^n;
        } 
        else
        {
            for(auto &n: nums1)
                ans = ans^n;
            for(auto &n: nums2)
                ans = ans^n;
        }
            
        return ans;
    }
};