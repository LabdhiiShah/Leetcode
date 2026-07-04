class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto &road: roads)
        {
            int u = road[0];
            int v = road[1];
            int w = road[2];

            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }

        int ans = INT_MAX;
        vector<bool> vis(n+1, false);
        queue<int> q;
        q.push(1);
        vis[1] = true;

        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            for(auto &[ngbr, w]: adj[node])
            {
                ans = min(ans, w);

                if(!vis[ngbr])
                {
                    vis[ngbr] = true;
                    q.push(ngbr);
                }
            }
        }
        return ans;
    }
};