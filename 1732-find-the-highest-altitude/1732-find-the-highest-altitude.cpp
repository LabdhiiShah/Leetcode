class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector <int> alts;
        alts.push_back(0);
        int largest = 0;
        int altitude = 0;
        
        for(auto& n: gain)
        {
            altitude += n;
            alts.push_back(altitude);
        }

        for(auto& n: alts)
        {
            largest = max(largest,n);
        }
        return largest;
    }
};