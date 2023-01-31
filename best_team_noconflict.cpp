// Problem Link https://leetcode.com/problems/best-team-with-no-conflicts/description/

class Solution
{
public:
    static bool comp(pair<int, int> a, pair<int, int> b)
    {
        if (a.second == b.second)
            return a.first < b.first;
        return a.second < b.second;
    }
    int bestTeamScore(vector<int> &scores, vector<int> &ages)
    {
        vector<pair<int, int>> players;
        for (int i = 0; i < scores.size(); i++)
        {
            players.push_back(make_pair(scores[i], ages[i]));
        }
        sort(players.begin(), players.end(), comp);
        vector<int> dp(scores.size());
        for (int i = 0; i < dp.size(); i++)
            dp[i] = players[i].first;
        int max_score = dp[0];
        for (int i = 1; i < players.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (players[j].first <= players[i].first)
                {
                    dp[i] = max(players[i].first + dp[j], dp[i]);
                }
            }
            max_score = max(max_score, dp[i]);
        }
        return max_score;
    }
};