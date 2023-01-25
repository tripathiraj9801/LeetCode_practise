// Problem Link https://leetcode.com/problems/find-the-town-judge/description/

class Solution
{
public:
    int findJudge(int n, vector<vector<int>> &trust)
    {
        if (n == 1)
        {
            return 1;
        }

        unordered_map<int, int> mp;
        vector<int> possibles;
        for (int i = 0; i < trust.size(); i++)
        {
            mp[trust[i][1]]++;
        }

        for (auto itr : mp)
        {
            if (itr.second == n - 1)
            {
                possibles.push_back(itr.first);
            }
        }

        for (int i = 0; i < possibles.size(); i++)
        {
            int found = 0;
            for (int j = 0; j < trust.size(); j++)
            {
                if (trust[j][0] == possibles[i])
                {
                    found = 1;
                    break;
                }
            }
            if (found == 0)
            {
                return possibles[i];
            }
        }
        return -1;
    }
};
