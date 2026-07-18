class Solution(object):
    def countSymmetricIntegers(self, low, high):
        count = 0
        for i in range(low,high+1):
            s = str(i)
            if(len(s) % 2 == 0):
                c = len(s) // 2
                a = sum(int(s[c]) for c in range(c))
                b = sum(int(s[c]) for c in range(c,len(s)))
                if(a == b):
                    count += 1
        return count
        