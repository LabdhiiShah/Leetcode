class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";
        for(auto& w: words)
        {
            int sum = 0;
            for(auto& letter: w)
            {
                int index = letter - 'a';
                sum += weights[index];
            }
            sum %= 26;
            ans = ans + (char)('z'-sum);
            sum = 0;
        }
        return ans;
    }
};