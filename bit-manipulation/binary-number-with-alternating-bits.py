class Solution:
    def hasAlternatingBits(self, n: int) -> bool:
        x = bin(n)
        s = x[2 : ]
        for i in range(1,len(s)):
            if(s[i] == s[i-1]):
                return False
        return True