class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.length(), m = word2.length();
        vector<int> fromRightSideMatchCount(n,0);
        vector<int> seq;
        bool canChange = true;

        int rightMatched = 0;
        int i = n-1, j = m-1;

        while(i >= 0)
        {
            if(j >= 0 && word1[i] == word2[j])
            {
                rightMatched++;
                j--;
            }

            fromRightSideMatchCount[i] = rightMatched;
            i--;
        }

        i = 0;
        j = 0;

        while(i < n && j < m)
        {
            if(word1[i] == word2[j])
            {
                seq.push_back(i);
                j++;
            }
            else if(canChange == true && i+1 < n && fromRightSideMatchCount[i+1] >= m-j-1)
            {
                seq.push_back(i);
                canChange = false;
                j++;
            }
            i++;
        }
        return j == m? seq: vector<int>();
    }
};