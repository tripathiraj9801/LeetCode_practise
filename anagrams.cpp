// Problem Link https://leetcode.com/problems/find-all-anagrams-in-a-string/description/
class Solution
{
public:
    vector<int> findAnagrams(string s2, string s1)
    {
        int N = s2.length(), j = 0;

        vector<int> s1v(26, 0);
        vector<int> curr(26, 0);
        vector<int> res;

        for (auto x : s1)
        {
            s1v[x - 'a']++;
        }

        int N1 = s1.length();

        for (int i = 0; i < N; i++)
        {
            curr[s2[i] - 'a']++;
            if (i - N1 >= 0)
            {
                curr[s2[i - N1] - 'a']--;
            }
            if (i + 1 >= N1)
            {
                if (curr == s1v)
                    res.push_back(i - N1 + 1);
            }
        }
        return res;
    }
};