// Problem Link  https://leetcode.com/problems/data-stream-as-disjoint-intervals/description/
class SummaryRanges
{
    vector<vector<int>> intervals;

public:
    SummaryRanges() {}

    void addNum(int value)
    {
        int start = value, end = value;
        auto it = intervals.begin();
        while (it != intervals.end())
        {
            if (it->at(1) + 1 < end)
            {
                ++it;
                continue;
            }
            if (it->at(0) - 1 > end)
                break;
            start = min(start, it->at(0));
            end = max(end, it->at(1));
            it = intervals.erase(it);
        }
        intervals.insert(it, {start, end});
    }

    vector<vector<int>> getIntervals()
    {
        return intervals;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */