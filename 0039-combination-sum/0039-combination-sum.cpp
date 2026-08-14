class Solution {
public:
    vector<vector<int>> combos;
    void explore(int i, int remaining, vector<int>& curr, vector<int>& candidates)
    {
        if(remaining == 0)
        {
            combos.push_back(curr);
            return;
        }
        if(remaining < 0 || i >= candidates.size()) return;

        curr.push_back(candidates[i]);
        explore(i,remaining-candidates[i],curr,candidates);
        curr.pop_back();
        explore(i+1,remaining,curr,candidates);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>curr;
        explore(0, target, curr, candidates);
        return combos;
    }
};