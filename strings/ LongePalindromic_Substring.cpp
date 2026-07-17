class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.size();
        if (n <= 1)
            return s;
        auto expandCenter = [&](int left, int right)
        {
            while (left >= 0 && right < n && s[left] == s[right])
            {
                left--;
                right++;
            }
            return s.substr(left + 1, right - left - 1);
        };
        string maxStr = s.substr(0, 1);
        for (int i = 0; i < n - 1; i++)
        {
            string odd = expandCenter(i, i);
            string even = expandCenter(i, i + 1);

            if (odd.length() > maxStr.length())
                maxStr = odd;
            if (even.length() > maxStr.length())
                maxStr = even;
        }
        return maxStr;
    }
};