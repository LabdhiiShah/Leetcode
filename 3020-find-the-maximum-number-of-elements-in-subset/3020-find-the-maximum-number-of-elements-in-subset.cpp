class Solution {
public:
    int maximumLength(vector<int>& nums) {

        unordered_map<long long,int> freq;
        for(auto& n: nums)
            freq[n]++;

        int ans = 1; 
        
        if(freq.count(1))
        {
            int length = (freq[1] % 2 == 0)? freq[1]-1: freq[1];
            ans = max(ans,length);
        }

        for(auto &n: freq)
        {
            int length = 0;
            long long curr = n.first;
            int count = n.second;

            if(curr == 1)
                continue;
            
            long long r = sqrt(curr);
            if(r*r == curr && freq.count(r) && freq[r] >= 2)
                continue;
            
            while (freq.count(curr) && freq[curr] >= 2)
            {
                length++;

                if (curr > 1000000000LL)
                    break;

                curr *= curr;
            }

            if(freq.count(curr))
                length = (length*2) + 1;
            else
                length = (length*2) - 1;

            ans = max(ans,length);
        }

        return ans;
    }
};
