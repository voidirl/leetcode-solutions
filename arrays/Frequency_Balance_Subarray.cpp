class Solution
{
public:
    int getLength(vector<int> &nums)
    {
        int n = nums.size();
        int ans = 1;
        for (int i = 0; i < n; i++)
        {
            unordered_map<int, int> freq;
            map<int, int> freqCnt;

            for (int j = i; j < n; j++)
            {
                int x = nums[j];
                int old = freq[x];
                if (old)
                {
                    if (--freqCnt[old] == 0)
                        freqCnt.erase(old);
                }
                freq[x]++;
                freqCnt[freq[x]]++;

                if (freq.size() == 1)
                {
                    ans = max(ans, j - i + 1);
                    continue;
                }
                if (freqCnt.size() != 2)
                    continue;
                auto it = freqCnt.begin();
                int f1 = it->first;
                ++it;
                int f2 = it->first;
                if (f2 == 2 * f1)
                    ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};