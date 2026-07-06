class Solution
{
public:
    bool canPlaceBalls(vector<int> &position, int dist, int balls)
    {
        int cntBalls = 1, last = position[0];
        for (int i = 0; i < position.size(); i++)
        {
            if (position[i] - last >= dist)
            {
                cntBalls++;
                last = position[i];
            }
            if (cntBalls >= balls)
                return true;
        }
        return false;
    }
    int maxDistance(vector<int> &position, int m)
    {
        sort(position.begin(), position.end());
        int n = position.size();
        int low = 1, high = position[n - 1] - position[0];
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (canPlaceBalls(position, mid, m) == true)
            {
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        return high;
    }
};
