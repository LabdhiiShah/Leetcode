class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        long long currMass = mass;
        for(int i = 0; i < asteroids.size(); i++)
        {
            if(asteroids[i] > currMass)
                return false;

            currMass += asteroids[i];
        }
        return true;
    }
};