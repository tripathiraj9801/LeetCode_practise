// Problem Link https://leetcode.com/problems/sort-characters-by-frequency/description/

class Solution
{
public:
    string frequencySort(string s)
    {
        unordered_map<char, int> ump;
        for (char i : s)
        {
            ump[i]++;
        }
        vector<pair<int, char>> v;
        for (auto i : ump)
        {
            v.push_back({i.second, i.first});
        }
        sort(v.begin(), v.end(), [](pair<int, char> &a, pair<int, char> &b)
             { return a.first > b.first; });

        string ans = "";

        for (auto i : v)
        {
            while (i.first--)
            {
                ans += i.second;
            }
        }

        return ans;
    }
};