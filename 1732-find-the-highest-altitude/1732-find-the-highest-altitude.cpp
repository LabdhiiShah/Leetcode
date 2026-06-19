class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int highest = 0;
        int altitude = 0;

        for(auto& g: gain)
        {
            altitude += g;
            highest = max(highest,altitude);
        }
        return highest;
    }
};