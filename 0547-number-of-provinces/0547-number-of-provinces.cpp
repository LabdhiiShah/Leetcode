class Solution {
public:
    void dfs(int src, vector<vector<int>> &matrix, vector<bool> &visited)
    {
        visited[src] = true;
        for(int i = 0; i < matrix.size(); i++)
        {
            if(matrix[src][i] && !visited[i])
                dfs(i,matrix,visited);
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int province = 0;
        int n = isConnected.size();
        vector<bool> visited(n,false);

        for(int i = 0; i < n; i++)
        {
            if(visited[i]) continue;
            province++;
            dfs(i,isConnected,visited);
        }
        return province;
    }
};