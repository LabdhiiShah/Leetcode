class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> lastIndex(26,0);
        vector<bool> taken(26,false);
        string result = "";

        for(int i = 0; i < s.length(); i++)
        {
            int idx = s[i] - 'a'; 
            lastIndex[idx] = i;
        }

        for(int i = 0; i < s.length(); i++)
        {
            int idx = s[i] - 'a';
            if(taken[idx]) continue;
            while(result.length() > 0 && result.back() > s[i] && lastIndex[result.back()-'a'] > i)
            {
                taken[result.back()-'a'] = false;
                result.pop_back();  
            }
            result.push_back(s[i]);
            taken[idx] = true;
        }
        return result;
    }
};