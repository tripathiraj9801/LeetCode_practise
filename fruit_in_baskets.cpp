// Problem Link https://leetcode.com/problems/fruit-into-baskets/description/

// class Solution
// {
// public:
//     int totalFruit(vector<int> &fruits)
//     {
//         map<int, int> basket;
//         int mx = 0;

//         int i = 0, j = 0;
//         int n = fruits.size();
//         while (i < n)
//         {
//             ++basket[fruits[i]];

//             while (j < n && (int)basket.size() > 2)
//             {
//                 if (basket[fruits[j]] == 1)
//                     basket.erase(fruits[j]);
//                 else
//                     --basket[fruits[j]];
//                 ++j;
//             }
//             mx = max(mx, i - j + 1);
//             ++i;
//         }
//         return mx;
//     }
// };

class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        unordered_map<int, int> um;
        int ans = 0;
        for (int i = 0, j = 0; j <= fruits.size(); j++)
        {
            if (j != fruits.size() && (um.size() < 2 || um.find(fruits[j]) != um.end()))
                um[fruits[j]]++;
            else
            {
                ans = max(ans, j - i);
                while (i < fruits.size() && um.size() != 1)
                {
                    um[fruits[i]]--;
                    if (um[fruits[i]] == 0)
                        um.erase(fruits[i]);
                    i++;
                }
                if (j != fruits.size())
                    um[fruits[j]]++;
            }
        }
        return ans;
    }
};