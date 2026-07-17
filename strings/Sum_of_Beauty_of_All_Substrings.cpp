class Solution
{
public:
    int beautySum(string s)
    {
        int n = s.size();
        int sumOfBeauty = 0;
        for (int i = 0; i < n; i++)
        {
            vector<int> freq(26, 0);
            for (int j = i; j < n; j++)
            {
                freq[s[j] - 'a']++;
                int maxx = INT_MIN, mini = INT_MAX;
                for (int ch = 0; ch < 26; ch++)
                {
                    int diff = freq[ch];
                    if (diff > 0)
                    {
                        maxx = max(maxx, diff);
                        mini = min(mini, diff);
                    }
                }
                sumOfBeauty += (maxx - mini);
            }
        }
        return sumOfBeauty;
    }
};