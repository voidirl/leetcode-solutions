class Solution
{
public:
    string frequencySort(string s)
    {
        unordered_map<char, int> mpp;
        for (char ch : s)
            mpp[ch]++;
        vector<string> buckets(s.length() + 1);
        for (auto it : mpp)
        {
            buckets[it.second].push_back(it.first);
        }
        string ans;
        for (int i = buckets.size() - 1; i >= 0; i--)
        {
            for (char ch : buckets[i])
            {
                ans.append(i, ch);
            }
        }
        return ans;
    }
};