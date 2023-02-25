// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int buy = INT_MAX;
//         int profit = 0;
//         int n = prices.size();

//         for(int i = 0;i<n;i++){
//             buy = min(buy,prices[i]);
//             profit = max(prices[i]-buy,profit);

//         }
//         return profit;
//     }
// };

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int buy = INT_MAX;
        int profit = 0;
        int n = prices.size();

        for (int i = 0; i < n; i++)
        {
            buy = min(buy, prices[i]);
            profit = max(prices[i] - buy, profit);
        }
        return profit;
    }
};