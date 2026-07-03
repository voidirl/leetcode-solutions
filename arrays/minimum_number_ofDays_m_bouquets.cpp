class Solution
{
public:
    int possible(vector<int> &bloomDay, int day, int m, int k)
    {
        int cnt = 0;
        int numOfBloom = 0;
        for (int i = 0; i < bloomDay.size(); i++)
        {
            if (bloomDay[i] <= day)
                cnt++;
            else
            {
                numOfBloom += (cnt / k);
                cnt = 0;
            }
        }
        numOfBloom += (cnt / k);
        return numOfBloom >= m;
    }
    int minDays(vector<int> &bloomDay, int m, int k)
    {
        long long val = m * 1LL * k * 1LL;
        if (val > bloomDay.size())
            return -1;
        int mini = INT_MAX, maxx = INT_MIN;
        for (int i = 0; i < bloomDay.size(); i++)
        {
            mini = min(mini, bloomDay[i]);
            maxx = max(maxx, bloomDay[i]);
        }
        int low = mini, high = maxx;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (possible(bloomDay, mid, m, k))
            {
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return low;
    }
};