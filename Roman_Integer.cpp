// Problem Link https://leetcode.com/problems/roman-to-integer/description/

class Solution
{
public:
    int romanToInt(string s)
    {
        int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, h = 0, j = 0, k = 0, l = 0, m = 0, n = 0;
        for (int i = 0; s[i] != '\0'; i++)
        {
            if (s[i] == 'I')
            {
                if (s[i + 1] == 'V')
                {
                    i++;
                    h++;
                }
                else if (s[i + 1] == 'X')
                {
                    i++;
                    j++;
                }
                else
                    a++;
            }
            else if (s[i] == 'V')
                b++;
            else if (s[i] == 'X')
            {
                if (s[i + 1] == 'L')
                {
                    i++;
                    k++;
                }
                else if (s[i + 1] == 'C')
                {
                    i++;
                    l++;
                }
                else
                    c++;
            }
            else if (s[i] == 'L')
                d++;
            else if (s[i] == 'C')
            {
                if (s[i + 1] == 'D')
                {
                    i++;
                    m++;
                }
                else if (s[i + 1] == 'M')
                {
                    i++;
                    n++;
                }
                else
                    e++;
            }
            else if (s[i] == 'D')
                f++;
            else if (s[i] == 'M')
                g++;
        }
        int sum = 0;
        sum = 1 * a + 5 * b + 10 * c + 50 * d + 100 * e + 500 * f + 1000 * g + h * 4 + j * 9 + k * 40 + l * 90 + m * 400 + n * 900;
        return sum;
    }
};