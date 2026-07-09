class Solution
{
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>> &mat)
    {
        int index = -1;
        int cnt_max = -1;
        int n = mat.size();
        for (int i = 0; i < n; i++)
        {
            int cnt = 0;
            int m = mat[i].size();
            for (int j = 0; j < m; j++)
            {
                cnt += mat[i][j];
            }
            if (cnt > cnt_max)
            {
                cnt_max = cnt;
                index = i;
            }
        }
        return {index, cnt_max};
    }
};