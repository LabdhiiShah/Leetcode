class Solution {
public:
    long long maxPoints(vector<int>& technique1, vector<int>& technique2, int k) {
        int n = technique1.size();
        long long pts = 0;
        vector<int> gain(n);
        for(auto &t: technique2)
            pts += t;

        for(int i = 0; i < n; i++)
        {
            gain[i] = technique1[i] - technique2[i];
        }

        sort(gain.begin(), gain.end());
        reverse(gain.begin(), gain.end());

        for(int i = 0; i < k; i++)
        {
            pts += gain[i];
        }
        for(int i = k; i < n && gain[i] > 0; i++)
        {
            pts += gain[i];
        }
        return pts;
    }
};