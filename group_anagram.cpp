// Problem Link https://leetcode.com/problems/group-anagrams/description/

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &str)
    {
        unordered_map<string, vector<string>> mp;
        for (auto &it : str)
        {
            string curr = it;
            sort(curr.begin(), curr.end());
            mp[curr].push_back(it);
        }
        vector<vector<string>> ans;
        for (auto &it : mp)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};
