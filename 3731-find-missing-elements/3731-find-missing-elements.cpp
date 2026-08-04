class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> missingOnes;
        int min = INT_MAX;
        int max = INT_MIN;
        for(auto &n: nums)
        {
            if(min > n) min = n;
            if(max < n) max = n;
        }

        vector<bool> track(max-min+1, false);
        for(auto &n: nums)
        {
            track[n-min] = true;
        }
        for(int i = 0; i < track.size(); i++)
        {
            if(track[i]) continue;
            missingOnes.push_back(min+i);
        }
        return missingOnes;
    }
};