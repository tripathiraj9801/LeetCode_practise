// Problem Link https://leetcode.com/problems/find-right-interval/description/

class Solution
{
public:
    vector<int> findRightInterval(vector<vector<int>> &intervals)
    {

        map<int, int> mp;
        vector<int> res;
        int n = intervals.size();
        for (int i = 0; i < n; ++i)
            mp[intervals[i][0]] = i;
        for (auto in : intervals)
        {
            auto itr = mp.lower_bound(in[1]);
            if (itr == mp.end())
                res.push_back(-1);
            else
                res.push_back(itr->second);
        }
        return res;
    }
};