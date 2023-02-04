// Problem Link - https://leetcode.com/problems/permutation-in-string/description/

class Solution
{
public:
    bool checkInclusion(string a, string b)
    {
        if (b.length() < a.length())
            return false;
        vector<int> tar(26), cur(26);
        int n = a.length(), m = b.length();
        for (int i = 0; i < n; i++)
        {
            tar[a[i] - 'a']++;
            cur[b[i] - 'a']++;
        }
        for (int i = n; i < m; i++)
        {
            if (cur == tar)
                return true;
            cur[b[i] - 'a']++;
            cur[b[i - n] - 'a']--;
        }
        return cur == tar;
    }
};