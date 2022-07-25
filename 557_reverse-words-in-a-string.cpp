class Solution {
public:
    void ReverseString(string& s, int l, int r)
    {
        while(l < r)
        {
            swap(s[l++], s[r--]);
        }
    }
    string reverseWords(string s) 
    {
        int end = s.size();
        int l = 0;
        int r = 0;
        bool first = true;
        int p = 0;//go through the string
        for(int p = 0 ; p < end ; p++)
        {
            if(s[p] == ' ')
            {
                //at first, l = 0
                if(first)
                {
                    first = false;
                }
                else
                {
                    l = r + 2;                    
                }
                r = p-1;
                ReverseString(s, l, r);
            }

            if(p == end-1)
            {
                //for case that no blank in a string
                if(first)
                {
                    first = false;
                }
                else
                {
                    l = r + 2;                    
                }
                r = p;
                ReverseString(s, l, r);
            }
        }
        return s;
    }
};