class Solution:
    def findJudge(self, N: int, trust: List[List[int]]) -> int:
        if N == 1:
            return 1

        trusts = [0] * (N + 1)
        istrusted_by = [0] * (N + 1)

        for a, b in trust:
            trusts[a] += 1
            istrusted_by[b] += 1

        for i in range(1, N + 1):
            if trusts[i] == 0 and istrusted_by[i] == N - 1:
                return i
        return -1