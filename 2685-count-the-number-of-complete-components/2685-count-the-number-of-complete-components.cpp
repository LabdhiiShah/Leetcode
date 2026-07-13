class Solution {
public:
    void adjlist(unordered_map<int, unordered_set<int>> &adjList, vector<vector<int>>& edges)
    {
        for(auto &edge: edges)
        {
            int u = edge[0];
            int v = edge[1];
            adjList[u].insert(v);
            adjList[v].insert(u);
        }
    }
    
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, unordered_set<int>> adjList;
        vector<bool> visited(n,false);
        int ans = 0;

        adjlist(adjList,edges);

        for(int i = 0; i < n; i++)
        {
            if(visited[i]) continue;

            queue<int> q;
            q.push(i);
            visited[i] = true;

            int nodeCount = 0, edgeCount = 0;
            while(!q.empty())
            {
                int u = q.front();
                q.pop();

                nodeCount++;
                edgeCount += adjList[u].size();

                for(auto &v: adjList[u])
                {
                    if(!visited[v])
                    {
                        q.push(v);
                        visited[v] = true;
                    }
                }
            }
            edgeCount /= 2;
            if(edgeCount == nodeCount * (nodeCount-1)/2)
                ans++;
        }
        return ans;
    }
};