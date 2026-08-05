class Solution {
public:
    void dfs(vector<vector<int>> &adjList, vector<bool> &visited, int src)
    {
        visited[src] = true;
        for(auto &ngbr: adjList[src])
        {
            if(!visited[ngbr])
                dfs(adjList, visited, ngbr);
        }
    }

    void buildAdj(vector<vector<int>> &adjList, vector<vector<int>>& invocations)
    {
        for(int i = 0; i < invocations.size(); i++)
        {
            int u = invocations[i][0];
            int v = invocations[i][1];
            adjList[u].push_back(v);
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<bool> visited(n,false);
        vector<vector<int>> adjList(n);
        buildAdj(adjList,invocations);
        dfs(adjList, visited, k);

        
        vector<int> unsuspicious(n);
        iota(unsuspicious.begin(), unsuspicious.end(), 0);

        for(auto &edge : invocations)
        {
            int u = edge[0];
            int v = edge[1];

            if(visited[u] == false && visited[v] == true) return unsuspicious;
        }
        unsuspicious.clear();
        for(int i = 0; i < n; i++)
           if(!visited[i]) unsuspicious.push_back(i);

        return unsuspicious;
    }
};