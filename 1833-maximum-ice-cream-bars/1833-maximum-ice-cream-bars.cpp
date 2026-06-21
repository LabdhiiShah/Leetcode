class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int cnt = 0;
        sort(costs.begin(), costs.end());
        for(auto& c: costs)
        {
            if(coins < c)
                continue;
            coins -= c;
            cnt++;    
        }
        return cnt;
    }
};