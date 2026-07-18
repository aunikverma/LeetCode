class Solution(object):
    def sumOfNumberAndReverse(self, num):
        if num == 0:
            return True
        for i in range(num):
            s = str(i)
            s = s[::-1]
            n = i + int(s)
            if n == num:
                return True
        return False
