// Problem Link https://leetcode.com/problems/ipo/

class Solution
{
public:
    int findMaximizedCapital(int k, int w, vector<int> &pft, vector<int> &c)
    {
        int n = pft.size();
        vector<pair<int, int>> p(n);
        set<int> s;

        for (int i = 0; i < n; i++)
            p[i] = {c[i], pft[i]};
        sort(p.begin(), p.end());
        reverse(p.begin(), p.end());

        while (s.size() and k)
        {
            w += *(--s.end());
            s.erase(--s.end());
            k--;

            while (p.size() and p.back().first <= w)
            {
                s.insert(p.back().second);
                p.pop_back();
            }
        }

        return w;
    }
};

// Solution II

class Solution
{
public:
    int findMaximizedCapital(int k, int w, vector<int> &pft, vector<int> &c)
    {
        int n = pft.size();
        vector<pair<int, int>> p(n);
        set<int> s;

        for (int i = 0; i < n; i++)
            p[i] = {c[i], pft[i]};
        sort(p.begin(), p.end());
        reverse(p.begin(), p.end());

        while (p.size() and p.back().first <= w)
        {
            s.insert(p.back().second);
            p.pop_back();
        }

        while (s.size() and k)
        {
            w += *(--s.end());
            s.erase(--s.end());
            k--;

            while (p.size() and p.back().first <= w)
            {
                s.insert(p.back().second);
                p.pop_back();
            }
        }

        return w;
    }
};