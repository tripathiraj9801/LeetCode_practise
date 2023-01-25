// Problem Link https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks/description/

class Solution
{
public:
    int minimumRounds(vector<int> &tasks)
    {
        unordered_map<int, int> m;
        for (auto x : tasks)
        {
            m[x]++;
        }
        int c = 0;
        for (auto x : m)
        {
            if (x.second > 4)
            {
                c += (x.second - 4) / 3;
                c += 2;
            }
            else if (x.second == 1)
                return -1;
            else if (x.second == 4)
                c += 2;
            else
                c
        }
        return c;
    }
};