class Solution {
public:
    int minimumPushes(string word) {
        int n = word.length();
        int ans = 0;
        if(n <= 8) return n;
        vector<int> alphabet(26,0);

        for(auto &c: word)
            alphabet[c-'a']++;

        sort(alphabet.begin(), alphabet.end(), greater<>());
        for(int i = 0; i < 26; i++)
        {
            if(alphabet[i] == 0) break;

            ans += alphabet[i] * (i / 8 + 1);
        }
        return ans;
    }
};