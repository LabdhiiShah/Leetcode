class Solution {
public:
    char processStr(string s, long long k) {
        long long length = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '*')
            {
                if(length > 0)
                    length--;
            }
            else if(s[i] == '#')
                length *= 2;

            else if(s[i] == '%')
                continue;

            else    
                length++;
        }
        if(k >= length)
            return '.';

        cout << length;

        for(int i = s.size()-1; i >= 0; i--)
        {
            if(s[i] == '*')
                length++;       
            else if(s[i] == '#')
            {
                length /= 2;
                k = (k >= length) ? k - length : k;
            }
            else if(s[i] == '%')
                k =  length - k - 1;
            else
                length--;

            if(k == length)
                return s[i];
        }
        return '.';
    }
};