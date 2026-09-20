class Solution {
public:
    int reverseDegree(string s) {
        int total = 0;
        for(int i = 0; i < s.length(); i++)
        {
            int prod = ('z' - s[i] + 1) * (i+1);
            total += prod;
        }
        return total;
    }
};

// a = 26 => (z-a+1)