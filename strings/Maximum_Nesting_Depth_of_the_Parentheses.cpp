class Solution
{
public:
    int maxDepth(string s)
    {
        int maxx = 0, curr = 0;
        for (char c : s)
        {
            if (c == '(')
            {
                curr++;
                maxx = max(maxx, curr);
            }
            if (c == ')')
                curr--;
        }
        return maxx;
    }
};