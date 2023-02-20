// Problem Link https://leetcode.com/problems/simplify-path/description/
class Solution
{
public:
    string simplifyPath(string path)
    {
        if (path.empty())
            return "";
        stringstream ss(path);
        string dir;
        stack<string> st;

        while (getline(ss, dir, '/'))
        {
            if (dir.empty() || dir == ".")
                continue;
            else if (dir == "..")
            {
                if (st.empty())
                    continue;
                st.pop();
            }
            else
            {
                st.push(dir);
            }
        }
        stack<string> st2;
        while (!st.empty())
        {
            st2.push(st.top());
            st.pop();
        }
        string res;
        while (!st2.empty())
        {
            res += "/" + st2.top();
            st2.pop();
        }
        if (res.empty())
            return "/";
        return res;
    }
};