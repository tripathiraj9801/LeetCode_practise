// Problem Link https://leetcode.com/problems/concatenated-words/

class Solution
{
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string> &words)
    {
        vector<string> result;
        for (auto str : words)
        {
            if (isConcatStr(words, str))
                result.push_back(str);
        }
        return result;
    }
    bool isConcatStr(vector<string> &words, string curr_str)
    {
        for (int i = 1; i < curr_str.size(); i++)
        {
            if ((find(words.begin(), words.end(), curr_str.substr(0, i)) != words.end()) &&
                    (find(words.begin(), words.end(), curr_str.substr(i)) != words.end()) ||
                isConcatStr(words, curr_str.substr(i)))
                return 1;
        }
        return 0;
    }
};