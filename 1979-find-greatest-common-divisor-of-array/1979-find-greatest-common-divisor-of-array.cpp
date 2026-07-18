class Solution {
public:
    int gcd(int a, int b)
    {
        while(b != 0)
        {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    int findGCD(vector<int>& nums) {
        int smallest = INT_MAX, greatest = INT_MIN;
        for(auto &num: nums)
        {
            if(num < smallest)
                smallest = min(num, smallest);
            if(num > greatest)
                greatest = max(num, greatest);
        }
        return gcd(smallest, greatest);
    }
};