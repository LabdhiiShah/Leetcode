class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        
        // must be within range
        for(int i = 1; i <= 9; i++)
        {
            int num = 0;
            for(int j = i; j <= 9; j++)
            {
                num = num * 10 + j;
                if(num > high) continue;
                if(low <= num && num <= high)
                    ans.push_back(num);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};