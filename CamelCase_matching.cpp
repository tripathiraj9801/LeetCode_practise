// Problem Link https://leetcode.com/problems/camelcase-matching/description/
class Solution
{
public:
    bool issame(string a1, string pattern){
        int i = 0, j = 0;
        while (j < a1.size()){
            if (i < pattern.size() && pattern[i] == a1[j]){
                i++;
            }
            else{
                if (a1[j] >= 'A' && a1[j] <= 'Z')
                    return false;
            }
            j++;
        }
        return i == pattern.size();
    }
    vector<bool> camelMatch(vector<string> &queries, string pattern){
        vector<bool> ans;
        for (auto ele : queries){
            if (issame(ele, pattern))
                ans.push_back(true);
            else
                ans.push_back(false);
        }
        return ans;
    }
};
