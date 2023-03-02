// Problem Link https://leetcode.com/problems/string-compression/description/
class Solution
{
public:
    int compress(vector<char> &chars)
    {
        int p = 0, k = 0;
        int n = chars.size();
        auto updateChars = [&]()
        {
            if (p != 1)
            {
                int num_len = floor(log10(p)) + 1;
                int pw = pow(10, num_len - 1);
                int temp = p;
                while (num_len-- > 0)
                {
                    int c = temp / pw;
                    chars[k++] = (c + '0');
                    temp -= c * pw;
                    pw /= 10;
                }
            }
        };
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
            {
                p = 1;
                k++;
            }
            else
            {
                if (chars[i] == chars[i - 1])
                {
                    p++;
                }
                else
                {
                    updateChars();
                    chars[k++] = chars[i];
                    p = 1;
                }
            }
        }
        updateChars();
        return k;
    }
};