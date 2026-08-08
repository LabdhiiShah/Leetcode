class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0)  return false;
        // return (((n & (n-1)) == 0) && (n > 0));
        int cnt = __builtin_popcount(n);
        return cnt == 1;
    }
};