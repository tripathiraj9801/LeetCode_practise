// Problem Link  https://leetcode.com/problems/word-break-ii/description/

class Solution
{
public:
    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        int n = s.size();
        unordered_set<string> word_Set(wordDict.begin(), wordDict.end());
        vector<vector<string>> dp(n + 1, vector<string>());
        dp[0].push_back("");

        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j <= n; ++j)
            {
                string temp = s.substr(i, j - i);
                if (dp[i].size() > 0 && word_Set.count(temp))
                {
                    for (auto x : dp[i])
                    {
                        dp[j].emplace_back(x + (x == "" ? "" : " ") + temp);
                    }
                }
            }
        }

        return dp[n];
    }
};

class Solution
{
private
    List<String> sentences;

public
    List<String> wordBreak(String s, List<String> wordDict)
    {
        Set<String> words = new HashSet<>(wordDict);
        sentences = new ArrayList<>();
        wordBreak(words, s, 0, "");
        return sentences;
    }

private
    void wordBreak(Set<String> words, String s, int i, String sentence)
    {
        if (i == s.length())
        {
            sentences.add(sentence);
            return;
        }

        for (int j = i; j < s.length(); j++)
        {
            String word = s.substring(i, j + 1);
            if (words.contains(word))
            {
                if (sentence.length() == 0)
                {
                    wordBreak(words, s, j + 1, sentence + word);
                }
                else
                {
                    wordBreak(words, s, j + 1, sentence + " " + word);
                }
            }
        }
    }
}