class Solution {
public:
    const int MOD = 1e9 + 7; 
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.length();
        vector<int> prefix(n, 0);
        vector<int> nonZeroCount(n, 0);
        vector<long long> concatenatedString(n,0);
        vector<long long> pow10(n+1);
        vector<int> ans;

        prefix[0] = s[0] - '0';
        nonZeroCount[0] = (s[0] - '0' == 0? 0:1);
        concatenatedString[0] = (s[0] - '0' == 0? 0:s[0]-'0');
        pow10[0] = 1;

        for(int i = 1; i <= n; i++)
        {
            // calculate power of 10
            pow10[i] = (pow10[i - 1] * 10) % MOD; 
        }

        for(int i = 1; i < n; i++)
        {
            // calculated prefix sum
            prefix[i] = prefix[i-1] + (s[i] - '0');
            // cout << prefix[i-1] << " " << s[i] << " = " << prefix[i] << endl;

            // calculated no.of non-zero digit till i
            nonZeroCount[i] = nonZeroCount[i-1] + (s[i] - '0' == 0? 0:1);

            // concatenate string till i    
            long long num = (s[i] - '0' == 0)? concatenatedString[i-1]: (concatenatedString[i-1]*10 + (s[i]-'0'))%MOD; 
            concatenatedString[i] = num;

        }

        for(int i = 0; i < queries.size(); i++)
        {
            int start = queries[i][0];
            int end = queries[i][1];
            int cnt = nonZeroCount[end] - (start ? nonZeroCount[start - 1] : 0);

            long long substr = (start == 0? concatenatedString[end] :(concatenatedString[end] - ((concatenatedString[start-1] * pow10[cnt]) % MOD) + MOD)%MOD);

            long long sum = prefix[end] - (start == 0? 0 : prefix[start-1]);
            cout << substr << "*" << sum  << substr*sum%MOD << endl;
            ans.push_back((substr*sum)%MOD);
        }
        return ans;
    }
};


