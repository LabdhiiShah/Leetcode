class Solution {
public:
    int maxProduct(int n) {
        int max1 = INT_MIN, max2 = INT_MIN;
        while(n != 0)
        {
            int d = n % 10;
            n = n / 10;

            if(d >= max1)
            {
                max2 = max1;
                max1 = d;
            }
            else if(d > max2) max2 = d;
        }
        return (max1 * max2);
    }
};