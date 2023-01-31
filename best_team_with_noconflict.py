# https://leetcode.com/problems/best-team-with-no-conflicts/description/
class Solution:
    def bestTeamScore(self, scores: List[int], ages: List[int]) -> int:
        pairs = sorted(zip(ages, scores))
        dp = [pair[1] for pair in pairs]
        answer = dp[0]
        for i in range(1,len(pairs)):
            score_i = pairs[i][1]
            for j in range(i):
                score_j = pairs[j][1]
                if score_j <= score_i:
                    dp[i] = max(dp[i],score_i+dp[j])
                    answer = max(answer,dp[i])
        return answer