class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        // must be a substring
        int cnt = 0;
        for(auto &str: patterns)
        {
            if(word.contains(str))
                cnt++;
        }
        return cnt;
    }
};