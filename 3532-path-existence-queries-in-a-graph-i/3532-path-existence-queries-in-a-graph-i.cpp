class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> component(n,-1);
        vector<bool> result;
        int compId = 0;
        component[0] = compId;

        for(int i = 1; i < n; i++)
        {
            if(nums[i] - nums[i-1] > maxDiff)
                compId++;
            component[i] = compId;
        }
        for(int i = 0; i < queries.size(); i++)
        {
            int u = queries[i][0];
            int v = queries[i][1];

            result.push_back(component[u] == component[v]);
        }
        return result;
    }
};