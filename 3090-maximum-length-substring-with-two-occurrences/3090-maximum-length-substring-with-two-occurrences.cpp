class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char,int> freq;
        int i = 0;
        int maxLen = 0;
        for(int j = 0; j < s.length(); j++)
        {
            freq[s[j]]++;
            while(freq[s[j]] > 2)
            {
                freq[s[i]]--; 
                i++;
            }
            maxLen = max(maxLen, j-i+1);
        }
        return maxLen;
    }
};