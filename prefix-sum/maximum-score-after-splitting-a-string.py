class Solution:
    def maxScore(self, s: str) -> int:
        m = 0
        for i in range(1, len(s)):
            s1 = s[0:i]
            x = s1.count("0")
            s2 = s[i:]
            y = s2.count("1")
            z = x + y
            if z > m:
                m = z
        return m
