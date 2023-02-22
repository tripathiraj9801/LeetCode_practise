// Problem Link https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

class Solution
{
public:
    bool canShip(vector<int> &weights, int days, int maxCapacity)
    {
        int currentDays = 1, currentCapacity = 0;
        for (int weight : weights)
        {
            if (weight > maxCapacity)
                return false;
            if (weight + currentCapacity > maxCapacity)
            {
                currentDays += 1;
                if (currentDays > days)
                    return false;
                currentCapacity = weight;
            }
            else
            {
                currentCapacity += weight;
            }
        }
        return true;
    }
    int shipWithinDays(vector<int> &weights, int days)
    {
        int capacity = 0, maxWeight = 0, sumWeights = 0;
        for (int weight : weights)
        {
            maxWeight = max(maxWeight, weight);
            sumWeights += weight;
        }
        int start = maxWeight, end = sumWeights;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (canShip(weights, days, mid))
            {
                capacity = mid;
                end = mid - 1;
            }
            else
                start = mid + 1;
        }
        return capacity;
    }
};