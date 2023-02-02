// Problem Link https://leetcode.com/problems/longest-valid-parentheses/description/

class Solution
{
    typedef long long int ll;

public:
    int longestValidParentheses(string st)
    {
        stack<pair<char, int>> s;
        int n = st.size();
        for (int i = 0; i < n; i++)
        {
            if (st[i] == ')' and !s.empty() and s.top().first == '(')
            {
                int t = s.top().second;
                st[t] = '*';
                st[i] = '*';
                s.pop();
            }
            else
                s.push({st[i], i});
        }
        ll mx = 0, cnt = 0;
        for (int i = 1; i < n; i++)
        {
            if (st[i] == '*')
                cnt = 1;
            while (i < n and st[i] == st[i - 1] and st[i] == '*')
            {
                cnt++;
                i++;
            }
            mx = max(mx, cnt);
            cnt = 0;
        }
        cout << mx << endl;
        return mx;
    }
};

// Using dynamic programming

class Solution
{
public:
    int longestValidParentheses(string s)
    {
        stack<int> st;
        st.push(-1);
        int ans = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
                st.push(i);
            else
            {
                st.pop();
                if (st.empty())
                    st.push(i);
                else
                    ans = max(ans, i - st.top());
            }
        }
        return ans;
    }
};