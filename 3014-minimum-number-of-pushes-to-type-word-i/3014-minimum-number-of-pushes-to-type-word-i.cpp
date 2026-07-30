class Solution {
public:
    int minimumPushes(string word) {
        int pushes = 0;
        int n = word.length();
        if(n < 8) return n;

        int push = 1;
        for(int i = 1; i <= n; i++)
        {
            pushes += push;
            if(i % 8 == 0) push++;
        }
        return pushes;
    }
};