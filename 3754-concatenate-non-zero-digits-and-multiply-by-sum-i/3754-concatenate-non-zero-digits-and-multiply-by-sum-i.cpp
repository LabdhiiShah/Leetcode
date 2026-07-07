class Solution {
public:
    long long sumAndMultiply(int n) {
        long long num = 0, x = 0, sum = 0;
        while(n > 0)
        {
            long long d = 0;
            if(n % 10 == 0)
            {
                n = n/10;
                continue;
            }

            d = n % 10;
            num = num*10 + d;
            n = n/10;
        }
        while(num > 0)
        {
            long long d = 0;
            d = num % 10;
            sum += d;
            x = x*10 + d;
            num /= 10;
        }
        return x*sum;
    }
};