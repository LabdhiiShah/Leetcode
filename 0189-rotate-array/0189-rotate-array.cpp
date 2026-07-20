class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(k == 0) return; 

        int n = nums.size();
        k %= n;

        auto reverse = [&](int i, int j) {
            while(i < j)
            {
                swap(nums[i],nums[j]);
                i++;
                j--;
            }
        };
        reverse(0,n-1);
        reverse(0,k-1);
        reverse(k,n-1);
        return;
    }
};