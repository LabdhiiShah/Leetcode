class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        stack<int> st;
        for(int i = 0; i < asteroids.size(); i++)
        {
            int curr = asteroids[i];
            if(!st.empty() && curr < 0 && st.top() > 0)
            {
                while(!st.empty() && st.top() > 0 && abs(curr) > abs(st.top()))
                    st.pop();

                if(st.empty() || st.top() < 0)
                    st.push(curr);
                
                else if(abs(curr) == abs(st.top()))
                    st.pop();
                
                else if(abs(curr) < abs(st.top()))
                    continue;
                
            }
            else 
                st.push(curr);
        }
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};