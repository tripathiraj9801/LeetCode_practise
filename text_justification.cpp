// Problem Link https://leetcode.com/problems/text-justification/description/

class Solution
{
public:
    vector<string> fullJustify(vector<string> &words, int maxWidth)
    {
        int n = words.size();
        vector<string> ans;
        int i = 0;
        while (i < n)
        {
            int j = i, numOfWord = 0, spaceBetween = 0;
            while (j < n && maxWidth >= (numOfWord + spaceBetween + words[j].size()))
            {
                numOfWord += words[j].size();
                spaceBetween++;
                j++;
            }
            spaceBetween--;
            string res = "";
            int rem = maxWidth - numOfWord;
            int numOfSpace = spaceBetween <= 0 ? 0 : rem / spaceBetween;
            int extraSpace = spaceBetween <= 0 ? 0 : rem % spaceBetween;
            if (j == n)
            {
                numOfSpace = 1;
                extraSpace = 0;
            }
            while (i < n && i < j)
            {
                res += words[i];
                int k = 0;
                while (spaceBetween > 0 && k < numOfSpace)
                {
                    res += " ";
                    k++;
                }
                spaceBetween--;
                if (extraSpace > 0)
                {
                    res += " ";
                    extraSpace--;
                }
                i++;
            }
            while (res.size() != maxWidth)
                res += " ";
            ans.push_back(res);
        }
        return ans;
    }
};

// class Solution {
// public:
//     vector<string> fullJustify(vector<string>& words, int maxWidth) {
//         vector<string> ans;
//         int n = words.size();

//         for(int i = 0, w; i < n; i = w) {
//             int len = 0;
//             for(w = i; w < n && len + words[w].length() + 1 <= maxWidth; w++) {
//                 len += words[w].length() + 1;
//         }

//             string str = words[i];
//             int space = 1, extra = 0;
//             if(w != i + 1 && w != words.size()) {
//                 space = (maxWidth - len) / (w - i - 1) + 1;
//                 extra = (maxWidth - len) % (w - i - 1);
//             }
//             for(int j = i + 1; j < w; ++j) {
//                 for(int s = space; s > 0; s--) str += ' ';
//                 if(extra-- > 0) str += ' ';
//                 str += words[j];
//             }
//             int strLen = maxWidth - str.length();
//             while(strLen-- > 0) str += ' ';
//             ans.push_back(str);
//         }
//         return ans;
//     }
// };