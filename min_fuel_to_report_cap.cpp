// Problem Link https://leetcode.com/problems/minimum-fuel-cost-to-report-to-the-capital/

class Solution
{
public:
    long long minimumFuelCost(vector<vector<int>> &roads, int seats)
    {
        int n = roads.size() + 1;
        vector<int> g[n];
        vector<int> deg(n, 0);
        for (auto i : roads)
        {
            g[i[0]].push_back(i[1]);
            g[i[1]].push_back(i[0]);
            deg[i[0]]++;
            deg[i[1]]++;
        }
        vector<int> people(n, 1);
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (deg[i] == 1)
                q.push(i);
        }
        long long ans = 0;
        while (!q.empty())
        {
            int sz = q.size();
            while (sz--)
            {
                int p = q.front();
                q.pop();
                if (p == 0)
                    break;
                ans += ceil(people[p] * 1.0 / seats);
                for (int v : g[p])
                {
                    deg[v]--;
                    people[v] += people[p];
                    if (deg[v] == 1)
                        q.push(v);
                }
            }
        }
        return ans;
    }
};