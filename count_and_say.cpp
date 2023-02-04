// Problem Link https://leetcode.com/problems/count-and-say/description/

class Solution
{
public:
    string countAndSay(int n)
    {
        string ans;
        for (int i = 1; i <= n; i++)
        {
            if (i == 1)
            {
                ans = to_string(i);
            }
            else
            {
                ans = say(ans);
            }
        }
        return ans;
    }
    string say(string str)
    {
        int n = str.size();
        string res = "";
        for (int i = 0; i < n;)
        {
            int k = i;
            while (k < n)
            {
                if (str[k] == str[i])
                {
                    k++;
                }
                else
                {
                    break;
                }
            }
            res += to_string(k - i) + str[i];
            i = k;
        }
        return res;
    }
};
