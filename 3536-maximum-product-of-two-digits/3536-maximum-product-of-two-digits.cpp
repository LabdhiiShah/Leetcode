class Solution {
public:
    int maxProduct(int n) {
        string s;
        while(n != 0)
        {
            int d = n % 10;
            s += (d + '0');
            n = n / 10;
        }
        sort(s.begin(), s.end(),greater<char>());
        return (s[0]-'0') * (s[1]-'0');
    }
};