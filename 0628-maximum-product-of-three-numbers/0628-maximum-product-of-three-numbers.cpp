class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
        int min1 = INT_MAX, min2 = INT_MAX;

        for(int i = 0; i < n; i++)
        {
            int number = nums[i];
            if(number > max1)
            {
                max3 = max2;
                max2 = max1;
                max1 = number;
            }
            else if(number > max2)
            {
                max3 = max2;
                max2 = number;
            }
            else if(number > max3)
                max3 = number;
            if(number < min1)
            {
                min2 = min1;
                min1 = number;
            }
            else if(number < min2)
                min2 = number;
        }

        int ans = max(max1*max2*max3, min1*min2*max1);
        return ans;
    }
};