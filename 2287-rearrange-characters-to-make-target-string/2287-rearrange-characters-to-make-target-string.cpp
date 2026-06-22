class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        int freqS[26] = {0};
        int freqT[26] = {0};

        for(auto& ch: s)
            freqS[ch - 'a']++;

        for(auto& ch: target)
            freqT[ch - 'a']++;

        int ans = INT_MAX;
        for(auto &t: target)
            ans = min(ans, freqS[t-'a']/freqT[t-'a']);
        
        return ans;
    }
};