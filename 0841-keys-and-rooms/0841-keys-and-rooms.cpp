class Solution {
public:
    void dfs(int src, vector<bool> &visited, vector<vector<int>> &rooms)
    {
        visited[src] = true;
        for(auto &key: rooms[src])
            if(!visited[key])
                dfs(key,visited,rooms);
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size());
        dfs(0,visited,rooms);
        bool ans = true;

        for(bool v: visited)
            if(!v) ans = false;

        return ans;
    }
};