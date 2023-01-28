// Problem Link

class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int result = -1;
        int size = gas.size();
        for (int i = 0; i < size; ++i)
        {
            int left = gas[i] - cost[i];
            if (left >= 0)
            {
                for (int c = 1, j = i + 1; c < size; ++c, ++j)
                {
                    if (j == size)
                        j = 0;
                    left += gas[j] - cost[j];
                    if (left < 0)
                    {
                        if (j > i)
                            i = j;
                        else
                            i = size;
                        break;
                    }
                }
                if (left >= 0)
                {
                    result = i;
                    break;
                }
            }
        }
        return result;
    }
};