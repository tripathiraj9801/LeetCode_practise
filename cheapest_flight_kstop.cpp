// Problem Link https://leetcode.com/problems/cheapest-flights-within-k-stops/description/

class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &f, int src, int dst, int k)
    {

        queue<pair<int, pair<int, int>>> pq;
        vector<int> dist(n, 1e9);
        pq.push({0, {0, src}});
        vector<vector<pair<int, int>>> v(n + 1);

        for (int i = 0; i < f.size(); i++)
        {
            v[f[i][0]].push_back({f[i][1], f[i][2]});
        }

        while (pq.empty() == false)
        {
            auto x = pq.front();
            int stop = x.first;
            int dis = x.second.first;
            int node = x.second.second;

            pq.pop();
            if (stop > k)
                continue;

            for (auto it : v[node])
            {
                if (dis + it.second < dist[it.first] && stop <= k)
                {
                    dist[it.first] = dis + it.second;
                    pq.push({stop + 1, {dist[it.first], it.first}});
                }
            }
        }
        if (dist[dst] == 1e9)
            return -1;
        return dist[dst];
    }
};
S