class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2) return n;
        int step1 = 1, step2 = 2, steps = 0;
        for(int i = 2; i < n; i++)
        {
            steps = step1 + step2;
            step1 = step2;
            step2 = steps;
        }
        return steps;
    }
};