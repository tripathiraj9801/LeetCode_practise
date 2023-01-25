// https://leetcode.com/problems/find-closest-node-to-given-two-nodes/description/

// Optimal approach is to implement BFSon nodes.
class Solution
{
public:
    void distarray(vector<int> &edges, int node1, vector<int> &dist, vector<int> adj[])
    {
        queue<int> q;
        q.push(node1);
        dist[node1] = 0;

        while (!q.empty())
        {
            int siz = q.size();
            for (int i = 0; i < siz; i++)
            {
                int node = q.front();
                q.pop();
                for (auto it : adj[node])
                {
                    if (dist[it] == INT_MAX)
                    {
                        dist[it] = dist[node] + 1;
                        q.push(it);
                    }
                }
            }
        }
    }
    int closestMeetingNode(vector<int> &edges, int node1, int node2)
    {

        int n = edges.size();
        vector<int> adj[n];
        for (int i = 0; i < n; i++)
        {
            if (edges[i] != -1)
            {
                adj[i].push_back(edges[i]);
            }
        }
        vector<int> dist1(n, INT_MAX);
        vector<int> dist2(n, INT_MAX);
        distarray(edges, node1, dist1, adj);
        distarray(edges, node2, dist2, adj);
        int w = INT_MAX;
        int z = -1;
        for (int i = 0; i < n; i++)
        {
            if (dist1[i] != INT_MAX && dist2[i] != INT_MAX)
            {
                int p = max(dist1[i], dist2[i]);
                if (w > p)
                {
                    w = p;
                    z = i;
                }
            }
        }
        return z;
    }
};