class Solution:
    def toHex(self, n: int) -> str:
        if(n < 0):
            n = 2**32 + n #if number is negative then convert in into two complement by think og 32 bit integer
        return hex(n)[2 : ]