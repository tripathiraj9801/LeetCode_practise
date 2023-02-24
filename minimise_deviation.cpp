// Problem Link https://leetcode.com/problems/minimize-deviation-in-array/description/

class Solution
{
public:
    int minimumDeviation(vector<int> &nums)
    {
        priority_queue<int> pq;
        int mini = INT_MAX;
        for (auto num : nums)
        {
            if (num % 2)
                num *= 2;
            pq.push(num);
            mini = min(mini, num);
        }
        int minDev = INT_MAX;
        while (1)
        {
            int maxVal = pq.top();
            pq.pop();
            minDev = min(maxVal - mini, minDev);
            if (maxVal % 2)
                break;
            maxVal /= 2;
            mini = min(mini, maxVal);
            pq.push(maxVal);
        }
        return minDev;
    }
};

//
class Solution
{
public:
    int minimumDeviation(vector<int> &nums)
    {
        priority_queue<int> pq;
        int minVal = INT_MAX;
        for (int num : nums)
        {
            if (num % 2 == 1)
                num = num * 2;
            pq.push(num);
            minVal = min(minVal, num);
        }
        int minDeviation = INT_MAX;
        while (true)
        {
            int maxVal = pq.top();
            pq.pop();
            minDeviation = min(minDeviation, maxVal - minVal);

            if (maxVal % 2 == 1)
                break;
            maxVal = maxVal / 2;
            minVal = min(minVal, maxVal);
            pq.push(maxVal);
        }
        return minDeviation;
    }
};