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
