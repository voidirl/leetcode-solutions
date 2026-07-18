class Solution
{
public:
    string say(string s)
    {
        if (s.size() == 0)
            return "1";
        string ans = "";
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            int cnt = 1;
            while (i < n - 1 && s[i] == s[i + 1])
            {
                i++;
                cnt++;
            }
            ans += to_string(cnt);
            ans += s[i];
        }
        return ans;
    }
    string countAndSay(int n)
    {
        string ans = "";
        while (n--)
        {
            ans = say(ans);
        }
        return ans;
    }
};